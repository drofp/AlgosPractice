#include "linked_lists.h"

namespace linkedlists {
void demoList() {
  SLinkedList<int> l;
  SLinkedListNode<int> n(7);
  SLinkedListNode<int> m(7);
  std::cout << "n->next: " << n.next << std::endl;
  l.insert(3);
  l.insert(5);
  l.insert(4);
  std::string s = l.toString();
  std::cout << s << std::endl;
  SLinkedListNode<int> *foundNode = l.find(5);
  std::cout << "foundNode data: " << foundNode->data << std::endl;
  std::cout << (foundNode == l.head->next) << std::endl;

  std::cout << "==================" << std::endl;
  std::cout << "playing with copy ctor" << std::endl;
  SLinkedList<int> *l2 = new SLinkedList<int>(l);
  std::cout << "l2 is: " << l2->toString() << std::endl;
  std::cout << "l2 head: " << l2->head << ',' << l2->head->data << '\n';
  std::cout << "l2 mid: " << l2->head->next << ',' << l2->head->next->data << '\n';
  std::cout << "l2 tail: " << l2->tail << ',' << l2->tail->data << '\n';

  std::cout << "==================" << std::endl;
  std::cout << "playing with move ctor" << std::endl;
  SLinkedListNode<int> n2(33);
  SLinkedListNode<int> n2moved = std::move(n2);

  std::cout << "==================" << std::endl;
  std::cout << "playing with assignment operators" << std::endl;
  SLinkedListNode<int> n3(55);
  SLinkedListNode<int> n3copyToMe;
  SLinkedListNode<int> n3moveToMe;
  n3copyToMe = n3;
  std::cout << "about to move..." << std::endl;
  n3moveToMe = std::move(n3);  // is copy elision working?
}
}  // namespace linkedlists