//
// Created by MingyangZeng on 2019-04-08.
//

#include "messageQueue.h"

void messageQueue::push(message *message) {
  if (_messages->empty()) {
    _messages->push_back(*message);
  } else {
    for (auto it = _messages->cbegin(); it != _messages->cend(); it++) {
      if (message->_update_time < (*it)._update_time) {
        _messages->insert(it, *message);
        return;
      }
    }
    _messages->push_back(*message);
  }
}

message *messageQueue::poll() {
  if (_messages->empty())
    return nullptr;
  message *front = &(_messages->front());
  _messages->pop_front();
  return front;
}

messageQueue::messageQueue() { _messages = new list<message>; }

int messageQueue::count() { return _messages->size(); }

message *messageQueue::peek() {
  if (_messages->empty())
    return nullptr;
  return &_messages->front();
}
