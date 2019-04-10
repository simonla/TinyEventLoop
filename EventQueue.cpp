//
// Created by MingyangZeng on 2019-04-08.
//

#include "EventQueue.h"
void EventQueue::push(Message message) {
  for (auto it = _messages->begin(); it != _messages->end(); it++) {
    if ((*it)._update_time > message._update_time) {
      _messages->insert(it, *it);
      break;
    }
  }
}

Message *EventQueue::poll() {
  if (_messages->empty()) {
    return nullptr;
  }
  Message *front = &(_messages->front());
  _messages->pop_front();
  return front;
}

EventQueue::EventQueue() { _messages = new list<Message>; }
