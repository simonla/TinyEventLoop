//
// Created by MingyangZeng on 2019-04-08.
//

#include "looper.h"
#include <cstring>
#include <iostream>
#include <sstream>

void looper::prepare() {
  _message_queen = new messageQueue();
  if (pipe(pipe_fd) < 0) {
    std::cout << "init pipe fail";
    throw std::bad_exception();
  }
  _pipe_fd_read = pipe_fd[0];
  _pipe_fd_write = pipe_fd[1];
  _event.events = EPOLLIN | EPOLLET;
  _ep_fd = epoll_create(MAX_EVENTS_COUNT);
  int ret;
  ret = epoll_ctl(_ep_fd, EPOLL_CTL_ADD, _pipe_fd_read, &_event);
  if (ret != 0) {
    closePipe();
    throw std::bad_exception();
  }
}

void looper::closePipe() const {
  close(_pipe_fd_write);
  close(_pipe_fd_read);
  close(_ep_fd);
}

void looper::loop() {
  if (_message_queen == nullptr) {
    throw std::bad_exception();
  }
  _is_Looping = true;
  while (_is_Looping) {
    if (_message_queen->count() == 0) {
      std::cout << "queen empty, block main thread" << std::endl;
      block(EPOLL_WAIT_INFINITE);
    }
    message *message = _message_queen->peek();
    if (message == nullptr)
      continue;
    if (message->_update_time <= util::now_time()) {
      message->run();
      _message_queen->poll();
    } else {
      std::cout << "handle this message later, block main thread" << std::endl;
      block(message->_update_time - util::now_time());
    }
  }
}

void looper::exit() {
  _is_Looping = false;
  closePipe();
}

void looper::post(message *message) {
  _message_queen->push(message);
  printf("post message to queen, now count = %d \n", _message_queen->count());
  if (!_is_Looping) {
    std::cout << "main thread blocked, wake up it first" << std::endl;
    // write to pipe to wake up a thread which block for I/O
    auto buf = malloc(1);
    if (write(_pipe_fd_write, buf, 1) == -1) {
      std::cout << "write fail" << std::endl;
      throw std::bad_exception();
    }
  } else {
    std::cout << "main thread is not blocked, do not need wake up" << std::endl;
  }
}

void looper::block(int time_out) {
  _is_Looping = false;
  std::stringstream ss;
  ss << time_out;
  std::string str_time_out = ss.str();
  if (time_out == -1) {
    str_time_out = "infinite";
  }
  std::cout << "main thread blocked, will wait for " + str_time_out + " ms"
            << std::endl;
  epoll_wait(_ep_fd, _events, MAX_EVENTS_COUNT, time_out);
  std::cout << "main thread wake up now" << std::endl;
  _is_Looping = true;
}