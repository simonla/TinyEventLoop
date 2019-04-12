//
// Created by MingyangZeng on 2019-04-08.
//

#include "Message.h"

void Message::run() { _fun(); }

Message::Message(callback fun, long delay_mills_time) {
  _fun = fun;
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now().time_since_epoch());
  _update_time = ms.count() + delay_mills_time;
}
