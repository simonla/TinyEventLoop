//
// Created by MingyangZeng on 2019-04-08.
//

#include "MessageQueue.h"
void MessageQueue::push(Message *message) {
  for (auto it = _messages->begin(); it != _messages->end(); it++) {
    if ((*it)._update_time > message->_update_time) {
      _messages->insert(it, *it);
      break;
    }
  }
}

Message *MessageQueue::poll() {
  if (_messages->empty()) {
    return nullptr;
  }
  Message *front = &(_messages->front());
  _messages->pop_front();
  return front;
}

MessageQueue::MessageQueue() { _messages = new list<Message>; }
