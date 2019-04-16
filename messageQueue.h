//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_EVENTLOOP_H
#define EVENTLOOPDEMO_EVENTLOOP_H

#include "message.h"
#include <list>

using std::list;

class messageQueue {
private:
  list<message> *_messages;

public:
  void push(message *message);
  messageQueue();
  message *peek();
  message *poll();
  int count();
};

#endif // EVENTLOOPDEMO_EVENTLOOP_H
