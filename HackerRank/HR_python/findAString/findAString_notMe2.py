# https://www.hackerrank.com/rest/contests/master/challenges/find-a-string/hackers/podliy16/download_solution?primary=true

def count_substring(big_str, small_str):
    small_len = len(small_str)
    count = 0

    for i in range(len(big_str[:-small_len + 1])):
        if(big_str[i:i+small_len] == small_str):
            count += 1

    return count

# if __name__ == '__main__':
#     print(count_substring('abaabca', 'a'))
