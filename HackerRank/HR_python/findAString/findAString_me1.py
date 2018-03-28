#  https://www.hackerrank.com/challenges/find-a-string/submissions/code/67624963


def count_substring(string, sub_string):
    subStringCount = 0
    ###########################
    # NOTE: ALL PRINT STATEMENTS ARE INVALUABLE DEBUG
    ###########################

    # Find first instance of substring, or return 0 instances
    if (string.find(sub_string) != -1):
        subStringCount += 1
        nextSubStringIndex = string.find(sub_string)
        # print("first SubstringLocation: " + str(nextSubStringIndex))
        # print()
    else:
        return 0

    # Check all subsequent characters
    while (nextSubStringIndex+1 < len(string)):
        # print("checking: {}".format(string[nextSubStringIndex+1:]))
        # print("next substring location: {}".format(nextSubStringIndex + string[nextSubStringIndex+1:].find(sub_string)))
        if (string[nextSubStringIndex+1:].find(sub_string) != -1):
            subStringCount += 1
            # print("nextSubStringIndex before: {}".format(nextSubStringIndex))
        else:
            break
        # print("string: {}".format(string))
        # print("index next substring: {}".format(string[nextSubStringIndex+1:].find(sub_string)))
        nextSubStringIndex += string[nextSubStringIndex +
                                     1:].find(sub_string) + 1
        # print("nextSubStringIndex after: {}".format(nextSubStringIndex))
        # print()

    return subStringCount


# if __name__ == '__main__':
#     print(count_substring('abaabca', 'a'))
