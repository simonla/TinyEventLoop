#include "Looper.h"
#include <iostream>

int main() {
  Looper looper;
  looper.prepare();
  printf("%s", "event loop ready...");
  looper.loop();
  return 0;
}
