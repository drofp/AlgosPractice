"""Various linked list implementations"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from typing import TypeVar

T = TypeVar("T")


class LinkedListS(object):
    """Singly linked list"""

    class LinkedListSNode(object):
        """Singly linked list node"""

        def __init__(self, data: T = None, next: LinkedListSNode = None):
            self.data = data
            self.next = next
    

    def __init__(self, initializer_data: T = None) -> None:
        self.head = None
        self.tail = None
        self.length = 1 if initializer_data else 0

        self.insert(initializer_data)

    def insert(self, input_data: T) -> None:
        """Inserts node at end of list."""
        new_node = LinkedListSNode(data=input_data)
        if head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
