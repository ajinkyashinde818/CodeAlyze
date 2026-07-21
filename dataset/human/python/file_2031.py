import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from collections import Counter
    from string import ascii_lowercase

    n = int(readline())
    s = input()
    ans = 0
    counter = Counter()

    for char in s:
        counter[char] += 1
        t = 1
        for char2 in ascii_lowercase:
            if char == char2:
                continue
            t *= (counter[char2] + 1)
            t %= MOD
        ans += t
        ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
