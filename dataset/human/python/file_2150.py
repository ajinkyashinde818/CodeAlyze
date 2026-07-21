import sys
import collections
import itertools
import math

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N = int(input())
    S = input().strip()

    MOD = 10 ** 9 + 7

    c = collections.Counter(S)

    ans = 1
    for i in range(0, 27):
        ans *= c[chr(i + ord('a'))] + 1

    ans -= 1

    print(ans % MOD)


if __name__ == '__main__':
    main()
