//
// Created by MingyangZeng on 2019-04-08.
//

#include "Looper.h"

void Looper::prepare() { eventLoop = new EventLoop(); }

void Looper::loop() {
  if (eventLoop == nullptr) {
    throw std::bad_exception();
  }
  _is_Looping = true;
  while (_is_Looping) {
    if (eventLoop->poll() == nullptr) {

    }
  }
}

void Looper::exit() { _is_Looping = false; }
