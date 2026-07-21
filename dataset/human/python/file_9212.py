import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    s = input()
    words = ["dream", "dreamer", "erase", "eraser"]

    while s:
        for word in words:
            if len(s) >= len(word):
                if s[-len(word):] == word:
                    s = s[:-len(word)]
                    break
        else:
            print("NO")
            sys.exit()

    print("YES")

if __name__ == '__main__':
    main()
