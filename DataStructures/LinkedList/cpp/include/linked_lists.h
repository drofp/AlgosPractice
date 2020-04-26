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
  SLinkedListNode<T> *head = nullptr;
  SLinkedListNode<T> *tail = nullptr;
  int size;

  bool insert(T val) {
    // TODO(drofp): Complete cycle checking by 4/28/20
    // if (cycleExists()) return false;
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
  std::string toString() {
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
  SLinkedListNode<T> find(T val);
  bool remove(T val, int numOfInstances);
  SLinkedListNode<T> extract(T val);
  bool replicate(T val);
  SLinkedListNode<T> reverse();
  bool cycleExists();
};

// dummy function for testing purposes
int addOne(int val);
void demoList();
}  // namespace linkedlists

#endif  // LINKED_LISTS_H_