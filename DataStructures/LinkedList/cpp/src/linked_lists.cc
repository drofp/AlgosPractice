#include "linked_lists.h"

namespace linkedlists {
// dummy for testing
int addOne(int val) { return val + 1; }
void demoList() {
  SLinkedList<int> l;
  l.insert(3);
  l.insert(5);
  l.insert(4);
  std::string s = l.toString();
  std::cout << s << std::endl;
}
}  // namespace linkedlists