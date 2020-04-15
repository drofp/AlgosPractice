from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import unittest

import linked_lists

class TestLinkedListS(unittest.TestCase):
    """Test singly linked list"""

    def test_initialization(self):
        """Test insertion on empty list"""
        l = linked_lists.LinkedListS(5)

        l.print_list()