//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_MESSAGE_H
#define EVENTLOOPDEMO_MESSAGE_H

#include "message.h"
#include <chrono>

typedef void (*callback)(long);

class message {
private:
  callback _fun;

public:
  long _delay_time;
  long _update_time;
  message(callback fun, long delay_mills_time);
  void run();
};

#endif // EVENTLOOPDEMO_MESSAGE_H
