#!/usr/bin/env python3

"""
Approximate solutions to the bin packing problem.

Reference material: 
https://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins/
- code examples are re-implemented in python for academic purposes

NOTE: 'c' is the bin capacity
"""

def online_next_fit(weights, c):
    num_of_bins = 0
    bin_remainder = c

    for weight in weights:
        if weight > bin_remainder:
            num_of_bins += 1
            bin_remainder = c - weight
        else:
            bin_remainder -= weight
    
    return num_of_bins

def online_first_fit(weights, c):
    num_of_bins = 0
    bin_remainders = [0] * len(weights)

    for weight in weights:
        j = 0
        while j < num_of_bins:
            if bin_remainders[j] >= weight:
                bin_remainders[j] = bin_remainders[j] - weight
                break
            j += 1
        if j == num_of_bins:
            bin_remainders[num_of_bins] = c - weight
            num_of_bins += 1
    
    return num_of_bins

def online_best_fit(weights, c):
    num_of_bins = 0
    bin_remainders = [0] * len(weights)

    for weight in weights:
        j = 0
        min_space_left = c + 1
        best_bin_idx = 0

        while j < num_of_bins:
            if bin_remainders[j] >= weight and \
            bin_remainders[j] - weight < min_space_left:
                best_bin_idx = j
                min_space_left = bin_remainders[j] - weight
            j += 1
        if min_space_left == c + 1:
            bin_remainders[num_of_bins] = c - weight
            num_of_bins += 1
        else:
            bin_remainders[best_bin_idx] -= weight
    
    return num_of_bins

def offline_first_fit_decr(weights, c):
    weights.sort(reverse=True)

    return online_first_fit(weights, c)
