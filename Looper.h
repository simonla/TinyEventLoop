//
// Created by MingyangZeng on 2019-04-08.
//

#ifndef EVENTLOOPDEMO_LOOPER_H
#define EVENTLOOPDEMO_LOOPER_H

#include "EventLoop.h"

class Looper {
private:
  EventLoop *eventLoop = nullptr;
  bool _is_Looping = true;

public:
  void prepare();

  void loop();

  void exit();
};

#endif // EVENTLOOPDEMO_LOOPER_H
