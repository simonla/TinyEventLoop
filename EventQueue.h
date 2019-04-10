//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_EVENTLOOP_H
#define EVENTLOOPDEMO_EVENTLOOP_H

#include "Message.h"
#include <list>

using std::list;

class EventQueue {
private:
  list<Message> *_messages;

public:
  void push(Message message);

  EventQueue();

  Message *poll();
};

#endif // EVENTLOOPDEMO_EVENTLOOP_H
