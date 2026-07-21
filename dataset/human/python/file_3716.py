from functools import reduce
from fractions import gcd
from collections import defaultdict
import math
import bisect
import itertools
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
INF = float("inf")


def prime_decomposition(n):
    i = 2
    ans = 0
    while i * i <= n:
        cnt = 1
        tmp = 0
        while n % i == 0:
            n = n // i
            tmp += 1
            if cnt == tmp:
                ans += 1
                cnt += 1
                tmp = 0
        i += 1
    if n > 1:
        ans += 1
    return ans


# 処理内容
def main():
    N = int(input())
    print(prime_decomposition(N))


if __name__ == '__main__':
    main()
