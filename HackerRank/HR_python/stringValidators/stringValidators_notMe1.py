# Alternate solution to "String Validators" problem: 
# https://www.hackerrank.com/challenges/string-validators/problem

def all_validators(string):
    print(any(x.isalnum() for x in string))
    print(any(x.isalpha() for x in string))
    print(any(x.isdigit() for x in string))
    print(any(x.islower() for x in string))
    print(any(x.isupper() for x in string))

if __name__ == '__main__':
    testCase = "0wERssa232d0"

    all_validators(testCase)
