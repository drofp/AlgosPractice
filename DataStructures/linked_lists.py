"""Various linked list implementations"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from typing import TypeVar

T = TypeVar("T")

class LinkedListS(object):
    """Singly linked list"""
    class LinkedListSNode(object):
        def __init__(self, data: T = None, next: LinkedListSNode = None):
            self.data = data
            self.next = next
    
    def __init__(self, 
                head: LinkedListSNode = None, 
                tail: LinkedListSNode = None) -> None:
        self.head = head
        self.tail = tail
