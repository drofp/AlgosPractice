#include "linked_lists.h"

namespace linkedlists {
SLinkedList::SLinkedList(){};
SLinkedList::~SLinkedList(){};

bool SLinkedList::insert(int val) { return val == 5 ? true : false; }

int addOne(int val) { return val + 1; }
}  // namespace linkedlists