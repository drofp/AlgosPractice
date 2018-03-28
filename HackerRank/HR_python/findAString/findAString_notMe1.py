# https://www.hackerrank.com/rest/contests/master/challenges/find-a-string/hackers/pkay1947/download_solution?primary=true


def count_substring(S, ss):
    count = 0
    for i in range(0, len(S)):
        count += S.count(ss,i,i+len(ss))
    return count

# if __name__ == '__main__':
#     print(count_substring('abaabca', 'a'))
