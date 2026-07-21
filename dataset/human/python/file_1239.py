import sys
import copy
import  math
import bisect
from collections import *
from operator import itemgetter
"""
from fractions import gcd
def lcm(x, y):
    return (x * y) // gcd(x, y)
"""
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
aaa = na()
s = aaa[0]
a = sum(aaa) - s
ans = abs(a - s)
for i in range(1, n-1):
    s += aaa[i]
    a -= aaa[i]
    ans = min(ans, abs(a - s))
print(ans)
