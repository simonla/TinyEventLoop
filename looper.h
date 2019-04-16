//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_LOOPER_H
#define EVENTLOOPDEMO_LOOPER_H

#include "messageQueue.h"
#include "util.h"
#include <malloc.h>
#include <sys/epoll.h>
#include <unistd.h>

class looper {
private:
  messageQueue *_message_queen = nullptr;
  bool _is_Looping = true;
  int _ep_fd{};
  struct epoll_event _event{};
  struct epoll_event _events[20]{};
  int pipe_fd[2]{};
  int _pipe_fd_read = pipe_fd[0];
  int _pipe_fd_write = pipe_fd[1];
  const int MAX_EVENTS_COUNT = 128;
  const int EPOLL_WAIT_INFINITE = -1;

  void block(int time_out);

public:
  void prepare();
  void loop();
  void exit();
  void post(message *message);
  void closePipe() const;
};

#endif // EVENTLOOPDEMO_LOOPER_H
