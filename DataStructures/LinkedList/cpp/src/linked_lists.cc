#include "linked_lists.h"

namespace linkedlists {
void demoList() {
  SLinkedList<int> l;
  SLinkedListNode<int> n(7);
  SLinkedListNode<int> m(7);
  l.insert(3);
  l.insert(5);
  l.insert(4);
  std::string s = l.toString();
  std::cout << s << std::endl;
  SLinkedListNode<int> *foundNode = l.find(5);
  std::cout << "foundNode data: " << foundNode->data << std::endl;
  std::cout << (foundNode == l.head->next) << std::endl;
}
}  // namespace linkedlists