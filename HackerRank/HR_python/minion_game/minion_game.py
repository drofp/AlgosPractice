# https://www.hackerrank.com/challenges/the-minion-game/problem


def minion_game(string):
    alphabet = [chr(x) for x in range(65, 91)]
    vowels = ['A', 'E', 'I', 'O', 'U']
    consonants = [l for l in alphabet if l not in vowels]

    print(*alphabet)
    print(*vowels)
    print(*consonants)

if __name__ == '__main__':
    minion_game("test")
