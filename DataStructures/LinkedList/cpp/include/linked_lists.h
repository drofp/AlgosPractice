#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

namespace linkedlists {
template <class T>
class SLinkedListNode {
 public:
  SLinkedListNode(T data): data(data) {}
  T data;
  SLinkedListNode *next = nullptr;
};

template <class T>
class SLinkedList {
 public:
  SLinkedListNode<T> *head {nullptr};
  SLinkedListNode<T> *tail {nullptr};
  int size {0};

  SLinkedList<T>() = default;
  ~SLinkedList<T>();

  bool insert(T val);
  std::string toString();
  SLinkedListNode<T> find(T val);
  bool remove(T val, int numOfInstances);
  SLinkedListNode<T> extract(T val);
  bool replicate(T val);
  SLinkedListNode<T> reverse();
  bool cycleExists();
};

// SLinkedList<T> methods
template<class T>
SLinkedList<T>::~SLinkedList<T>() {
  SLinkedListNode<T> *deleter = head;
  SLinkedListNode<T> *tmp = deleter;
  while (deleter != nullptr) {
    deleter = deleter->next;
    delete tmp;
    tmp = deleter;
  }
}

template<class T>
bool SLinkedList<T>::insert(T val) {
  // TODO(drofp): Complete cycle checking by 4/28/20
  // if (cycleExists()) return false;
  size++;
  if (head == nullptr) {
    head = new SLinkedListNode<T>(val);
    tail = head;
    return true;
  }
  SLinkedListNode<T> *newNode = new SLinkedListNode<T>(val);
  tail->next = newNode;
  tail = tail->next;
  return true;
}

template<class T>
std::string SLinkedList<T>::toString() {
  SLinkedListNode<T> *iterNode = head;
  std::stringstream s;
  std::string out;
  while (iterNode != nullptr) {
    s << iterNode->data;
    out += s.str();
    out += "->";
    // https://stackoverflow.com/questions/20731/how-do-you-clear-a-stringstream-variable
    std::stringstream().swap(s);
    iterNode = iterNode->next;
  }
  return out;
}

void demoList();
}  // namespace linkedlists

#endif  // LINKED_LISTS_H_