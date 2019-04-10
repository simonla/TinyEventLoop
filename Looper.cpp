//
// Created by MingyangZeng on 2019-04-08.
//

#include "Looper.h"
#include <sys/epoll.h>

void Looper::prepare() { eventLoop = new EventQueue();

}

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
