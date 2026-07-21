from fractions import gcd
from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
import sys
from bisect import *
import itertools
import copy
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7


def modpow(a, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res


def modinv(a, mod):
    return modpow(a, mod - 2, mod)


def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = float("inf")
    s = a[0]
    su = sum(a) - a[0]
    ans = min(ans , abs(s - su))
    for i in range(1, n-1):
        s += a[i]
        su -=a[i]
        ans = min(ans, abs(s - su))
    print(ans)
    



if __name__ == '__main__':
    main()
