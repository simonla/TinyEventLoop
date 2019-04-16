#include "looper.h"
#include "message.h"
#include <functional>
#include <iostream>
#include <pthread.h>
#include <random>

void do_other_things();
void *postMassage(void *args);
looper looper;

int main() {
  looper.prepare();
  std::cout << "message loop ready..." << std::endl;
  do_other_things();
  looper.loop();
  return 0;
}

void print_something(long prt) {
  auto *ms = reinterpret_cast<message *>(prt);
  printf("------------------------this message delay "
         "%ld------------------------\n",
         ms->_delay_time);
}

void *postMassage(void *args) {
  sleep(1);
  std::random_device rd;
  std::default_random_engine gen = std::default_random_engine(rd());
  std::uniform_int_distribution<int> dis(0, 20*1000);
  for (int i = 0; i < 10; ++i) {
    auto *message = new class message(print_something, dis(gen) );
    looper.post(message);
  }
  return nullptr;
}

void do_other_things() {
  pthread_t pthread;
  if (pthread_create(&pthread, nullptr, postMassage, nullptr) != 0) {
    std::cout << "create thread fail" << std::endl;
  }
}
