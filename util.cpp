//
// Created by simonla on 2019/4/15.
//

#include "util.h"
#include <chrono>

long util::now_time() {
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now().time_since_epoch());
  return ms.count();
}
