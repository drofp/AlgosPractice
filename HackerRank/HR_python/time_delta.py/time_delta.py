#!/bin/python3

"""
    Taken from: https://www.hackerrank.com/challenges/python-time-delta/problem

    Compute the time in seconds between two dates in any given timezone.

    Input (from console):
    int     - number of test cases. each test case is two lines
    str     - (variable) each test case in the format: "dayOfWeek day month year militaryTime timeZoneDifference"
"""

# Might come in Handy: https://stackoverflow.com/questions/3418050/month-name-to-month-number-and-vice-versa-in-python
# and: https://stackoverflow.com/questions/4362491/how-do-i-check-the-difference-in-seconds-between-two-dates
# and: https://gist.github.com/amalgjose/c767a4846d6ecaa3b6d7
# and: https://docs.python.org/3/library/datetime.html
# and: https://docs.python.org/3/library/calendar.html#calendar.TextCalendar

import math
import os
import random
import re
import sys
import datetime as dt

# Complete the time_delta function below.


def time_delta(t1, t2):
    _, day1, month1, year1, time1, tZone1 = t1.split()
    _, day2, month2, year2, time2, tZone2 = t2.split()

    day1, month1, year1 = map(int, [day1, month1, year1])
    day2, month2, year2 = map(int, [day2, month2, year2])

    hour1, min1, sec1 = map(int, time1.split(":"))
    hour2, min2, sec2 = map(int, time2.split(":"))

    dateAndTime1 = dt.datetime(year1, month1, day1, hour1, min1, sec1)
    dateAndTime2 = dt.datetime(year2, month2, day2, hour2, min2, sec2)

    return str(int((dateAndTime1 - dateAndTime2).total_seconds()))


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()

        t2 = input()

        delta = time_delta(t1, t2)

        fptr.write(delta + '\n')

    fptr.close()
