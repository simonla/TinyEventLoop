//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_LOOPER_H
#define EVENTLOOPDEMO_LOOPER_H

#include "MessageQueue.h"
#include <sys/epoll.h>
#include <unistd.h>
#include <malloc.h>

class Looper {
private:
  MessageQueue *_message_queen = nullptr;
  bool _is_Looping = true;
  int _ep_fd;
  struct epoll_event _event;
  struct epoll_event _events[20];
  int _pipe_fd_read;
  int _pipe_fd_write;
  const int MAX_EVENTS = 128;
  const int EPOLL_WAIT_TIMEOUT = -1; // set -1 for infinite time out
  long now_time() const ;

public:
  void prepare();
  void loop();
  void exit();
  void post(Message *message);
  void closePipe() const;

};

#endif // EVENTLOOPDEMO_LOOPER_H
