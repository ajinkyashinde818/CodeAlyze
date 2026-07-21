import math
import collections
import fractions
import itertools
import functools
import operator
import bisect

def lowmod(a, b, mod):
    a -= b
    if a >= mod:
        a -= mod
    return a

def solve():
    n = int(input())
    s = input()
    c = collections.Counter(s)
    mod = 10**9+7
    ans = 1
    for i in c:
        ans *= (c[i]+1)
        ans %= mod
    ans = lowmod(ans, 1, mod)
    print(ans)
    return 0

if __name__ == "__main__":
    solve()
