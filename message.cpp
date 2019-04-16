//
// Created by MingyangZeng on 2019-04-08.
//

#include "message.h"
#include "util.h"
#include <cstdio>

void message::run() { _fun(reinterpret_cast<long>(this)); }

message::message(callback fun, long delay_mills_time) {
  _fun = fun;
  _delay_time = delay_mills_time;
  _update_time = util::now_time() + delay_mills_time;
}
