# My solution to "String Validators" Problem:
# https://www.hackerrank.com/challenges/string-validators/problem
# 


def alpha_numeric(string):
    for c in range(len(string)):
        if string[c].isalnum():
            print(True)
            # print("alnum")
            break
        elif c == len(string)-1 and string[c].isalnum() is not True:
            print(False)
            # print("alnum")


def alpha(string):
    for c in range(len(string)):
        if string[c].isalpha():
            print(True)
            # print("alpha")
            break
        elif c == len(string)-1 and string[c].isalpha() is not True:
            print(False)
            # print("alpha")


def digit(string):
    for c in range(len(string)):
        if string[c].isdigit():
            print(True)
            # print("digit")
            break
        elif c == len(string)-1 and string[c].isdigit() is not True:
            print(False)
            # print("digit")

def lower(string):
    for c in range(len(string)):
        if string[c].islower():
            print(True)
            # print("lower")
            break
        elif c == len(string)-1 and string[c].islower() is not True:
            print(False)
            # print("lower")

def upper(string):
    for c in range(len(string)):
        if string[c].isupper():
            print(True)
            # print("upper")
            break
        elif c == len(string)-1 and string[c].isupper() is not True:
            print(False)
            # print("upper")

def all_validators(string):
    """
    Check for empty string, then run all validation tests
    """

    if string == "":
        print(5*(False+"\n"))
        print("empty string")
    else:
        alpha_numeric(s)
        alpha(s)
        digit(s)
        lower(s)
        upper(s)

if __name__ == '__main__':
    s="qQQ2"

    all_validators(s)
