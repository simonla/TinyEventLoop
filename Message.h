//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_MESSAGE_H
#define EVENTLOOPDEMO_MESSAGE_H

typedef void (*callback)();
#include <chrono>

class Message {
private:
  callback _fun;

public:
  long _update_time;
  Message(callback fun, long delay_mills_time);
  void run();
};

#endif // EVENTLOOPDEMO_MESSAGE_H
