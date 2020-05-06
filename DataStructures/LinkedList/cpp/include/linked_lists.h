#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

namespace linkedlists {
template <class T>
class SLinkedListNode {
 public:
  T data;
  SLinkedListNode *next = nullptr;
  SLinkedListNode() = default;
  SLinkedListNode(T data): data(data) {}
  ~SLinkedListNode() = default;
  friend void swap(SLinkedListNode<T> &first, SLinkedListNode<T> &second) {
    using std::swap;
    swap(first.data, second.data);
    swap(first.next, second.next);
  }
  SLinkedListNode(const SLinkedListNode<T> &other);
  SLinkedListNode(SLinkedListNode<T> &&other) noexcept;
  SLinkedListNode<T>& operator=(SLinkedListNode<T> other) noexcept;
};

template <class T>
bool operator==(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode);

template <class T>
bool operator!=(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode);

template <class T>
bool operator<(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode);

template <class T>
bool operator>(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode);

template <class T>
bool operator<=(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode);

template <class T>
bool operator>=(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode);

/*
// SLinkedListNode<T> methods
*/

//// WHY DOESN'T THIS WORK???
// explanations/alternatives:
// https://stackoverflow.com/questions/7331085/unresolved-external-using-template-class-with-copy-and-swap
// https://books.google.com/books?id=5w1TDwAAQBAJ&pg=PA627&lpg=PA627&dq=template+copy+and+swap&source=bl&ots=shgBQCHZmV&sig=ACfU3U3BDCmcRclpdWCTeFQien4W6u8Fdg&hl=en&sa=X&ved=2ahUKEwim6vDS5J_pAhUIbq0KHeexCQkQ6AEwCHoECAkQAQ#v=onepage&q=template%20copy%20and%20swap&f=false
// template <class T>
// void swap(SLinkedListNode<T> &first, SLinkedListNode<T> &second) {
//   using std::swap;
//   swap(first.data, second.data);
//   swap(first.next, second.next);
// }

template <class T>
SLinkedListNode<T>::SLinkedListNode(const SLinkedListNode<T> &other)
    : data{other.data},
      next{other.next} {
  std::cout << "copy ctor!" << std::endl;
}

template <class T>
SLinkedListNode<T>::SLinkedListNode(SLinkedListNode<T> &&other) noexcept
    : SLinkedListNode() {
  std::cout << "move ctor!" << std::endl;
  swap(*this, other);

  //// ALTERNATIVE
  // data = std::exchange(other.data, 0);
  // next = other.next;
  // other.next = nullptr;
}

template <class T>
SLinkedListNode<T>& SLinkedListNode<T>::operator=(SLinkedListNode<T> other)
    noexcept {
  std::cout << "assignment operator!" << std::endl;
  swap(*this, other);
  return *this;
}

// template <class T>
// SLinkedListNode<T>& SLinkedListNode<T>::operator=(
//     const SLinkedListNode<T> &other) {
//   // alternative: https://cpppatterns.com/patterns/copy-and-swap.html
//   if (&other == this) {
//     return *this;
//   }
//   data = other.data;
//   if (other.next != nullptr) {
//     next = new SLinkedListNode<T>(*other.next);
//     std::cout<< "copied!" << '\n';
//   }
//   return *this;
// }

// template <class T>
// SLinkedListNode<T>& SLinkedListNode<T>::operator=(
//    SLinkedListNode<T> &&other) {

//    }

template<class T>
bool operator==(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode) {
  return lNode.data == rNode.data;
}

template<class T>
bool operator!=(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode) {
  return lNode.data != rNode.data;
}

template<class T>
bool operator<(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode) {
  return lNode.data < rNode.data;
}

template<class T>
bool operator>(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode) {
  return lNode.data > rNode.data;
}

template<class T>
bool operator<=(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode) {
  return lNode.data <= rNode.data;
}

template<class T>
bool operator>=(const SLinkedListNode<T> &lNode,
                const SLinkedListNode<T> &rNode) {
  return lNode.data >= rNode.data;
}

template <class T>
class SLinkedList {
 public:
  SLinkedListNode<T> *head {nullptr};
  SLinkedListNode<T> *tail {nullptr};
  int size {0};

  SLinkedList() = default;
  ~SLinkedList();
  SLinkedList(const SLinkedList<T> &other);
  SLinkedList(SLinkedList<T> &&other);
  SLinkedList<T>& operator=(const SLinkedList<T> &other);
  SLinkedList<T>& operator=(SLinkedList<T> &&other);

  bool insert(T val);
  std::string toString();
  SLinkedListNode<T>* find(T val);  // finds first instance
  bool remove(T val, int numOfInstances);
  SLinkedListNode<T> extract(T val);
  bool replicate(T val);
  SLinkedListNode<T> reverse();
  bool cycleExists();
};

/*
// SLinkedList<T> methods
*/
template<class T>
SLinkedList<T>::~SLinkedList() {
  SLinkedListNode<T> *deleter = head;
  SLinkedListNode<T> *tmp = deleter;
  while (deleter != nullptr) {
    deleter = deleter->next;
    delete tmp;
    tmp = deleter;
  }
}

template<class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T> &other)
    : head{new SLinkedListNode<T>{other.head->data}},
      tail{new SLinkedListNode<T>{other.tail->data}},
      size{other.size} {
  SLinkedListNode<T> *iterNode = other.head->next;
  SLinkedListNode<T> *tmpNode = head;
  while (iterNode->next != nullptr || iterNode != other.tail) {
    tmpNode->next = new SLinkedListNode<T>(iterNode->data);
    iterNode = iterNode->next;
    tmpNode = tmpNode->next;
  }
  tmpNode->next = tail;
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

template<class T>
SLinkedListNode<T>* SLinkedList<T>::find(T val) {
  SLinkedListNode<T> *iterNode = head;
  while (iterNode != nullptr) {
    if (iterNode->data == val) {
      return iterNode;
    }
    iterNode = iterNode->next;
  }
  return nullptr;
}

void demoList();
}  // namespace linkedlists

#endif  // LINKED_LISTS_H_