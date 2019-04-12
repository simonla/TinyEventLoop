//
// Created by MingyangZeng on 2019-04-08.
//

#include "Looper.h"

void Looper::prepare() {
  _message_queen = new MessageQueue();
  int ret;
  int fds[2] = {_pipe_fd_read, _pipe_fd_write};
  if (pipe(fds) < 0) {
    throw std::bad_exception();
  }
  _event.data.fd = _pipe_fd_read;
  _event.events = EPOLLIN | EPOLLET;
  _ep_fd = epoll_create(MAX_EVENTS);
  ret = epoll_ctl(_ep_fd, EPOLL_CTL_ADD, _pipe_fd_read, &_event);
  if (ret != 0) {
    closePipe();
    throw std::bad_exception();
  }
}

void Looper::closePipe() const {
  close(_pipe_fd_write);
  close(_pipe_fd_read);
  close(_ep_fd);
}

void Looper::loop() {
  if (_message_queen == nullptr) {
    throw std::bad_exception();
  }
  _is_Looping = true;
  while (_is_Looping) {
    if (_message_queen->poll() == nullptr) {
      epoll_wait(_ep_fd, _events, MAX_EVENTS, EPOLL_WAIT_TIMEOUT);
    }
    Message *message = _message_queen->poll();
    if (message->_update_time <= now_time()) {
      message->run();
    } else {
      epoll_wait(_ep_fd, _events, MAX_EVENTS,
                 message->_update_time - now_time());
    }
  }
}

void Looper::exit() {
  _is_Looping = false;
  closePipe();
}

void Looper::post(Message *message) {
  _message_queen->push(message);
  if (!_is_Looping) {
    // write 1 byte to wake up a thread which block for I/O
    auto buf = malloc(1);
    if (write(_pipe_fd_write, buf, 1) == -1) {
      throw std::bad_exception();
    }
  }
}

long Looper::now_time() const {
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now().time_since_epoch());
  return ms.count();
}
