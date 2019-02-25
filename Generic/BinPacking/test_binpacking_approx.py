#!/usr/bin/env python3

import binpacking_approx

import unittest

class TestBinPacking(unittest.TestCase):
    def test_online_next_fit(self):
        weights = [2, 5, 4, 7, 1, 3, 8]
        c = 10

        result = binpacking_approx.online_next_fit(weights, c)
        self.assertEqual(result, 4)

    def test_online_first_fit(self):
        weights = [2, 5, 4, 7, 1, 3, 8]
        c = 10

        result = binpacking_approx.online_first_fit(weights, c)
        self.assertEqual(result, 4)

    def test_online_best_fit(self):
        weights = [2, 5, 4, 7, 1, 3, 8]
        c = 10

        result = binpacking_approx.online_best_fit(weights, c)
        self.assertEqual(result, 4)

    def test_offline_first_fit(self):
        weights = [2, 5, 4, 7, 1, 3, 8]
        c = 10

        result = binpacking_approx.offline_first_fit_decr(weights, c)
        self.assertEqual(result, 3)
