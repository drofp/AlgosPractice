"""Various linked list implementations"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from typing import TypeVar, Type

T = TypeVar("T")
TLinkedListSNode = TypeVar("TLinkedListSNode", bound="LinkedListSNode")

class LinkedListSNode(object):
    """Singly linked list node"""

    def __init__(self, data: T = None, next_node: TLinkedListSNode = None):
        self.data = data
        self.next_node = next_node
class LinkedListS(object):
    """Singly linked list"""
    
    def __init__(self, initializer_data: T = None) -> None:
        self.head = None
        self.tail = None
        self.length = 1 if initializer_data else 0

        if initializer_data:
            self.insert(initializer_data)

    def insert(self, input_data: T) -> None:
        """Inserts node at end of list."""
        new_node = LinkedListSNode(data=input_data)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next_node = new_node
            self.tail = new_node
    
    def delete(self, deletion_data: T, occurances: int = None) -> bool:
        """Delete specified occurances of nodes containing `deletion_data`.

        Deletion order is in order of occurance starting from head.

        Args:
          deletion_data: [T], the data contained by the node(s) to be removed 
              from the list
          occurances: [int], number of occurances to remove, starting from the 
              head of the list. If `None`, removes all occurances from list

        Returns:
          [bool], returns True on success
        """

        if occurances is None:
            occurances = 1

        curr_node = LinkedListSNode("temp")
        curr_node.next_node = self.head

        while curr_node.next_node and occurances > 0:
            if curr_node.next_node.data == deletion_data:
                occurances -= 1

                if curr_node.next_node is self.head:
                    self.head = self.head.next_node
                else:
                    curr_node.next_node = curr_node.next_node.next_node
                    
            curr_node = curr_node.next_node

        return False

    def search(self, search_data: T) -> LinkedListSNode:
        """Finds node with `search_data` in list. Returns None if not found.
        
        Performs linear search starting from head of list.
        """

        curr_node = self.head

        while curr_node:
            if curr_node.data == search_data:
                return curr_node
            curr_node = curr_node.next_node

        return None

    def print_list(self):
        """Print list starting from head"""
        curr_node = self.head
        while curr_node:
            print("{} -> ".format(curr_node.data), end="")
            curr_node = curr_node.next_node
        
        print()

