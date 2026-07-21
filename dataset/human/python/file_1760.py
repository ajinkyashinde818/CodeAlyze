import sys
import copy
import string
import  math
from _bisect import *
from collections import *
from operator import itemgetter
from math import factorial
"""
from fractions import gcd
def lcm(x, y):
    return (x * y) // gcd(x, y)
"""
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n, m = na()
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]
ans = 'No'
for i in range(n-m+1):
    for j in range(n-m+1):
        flag = True
        for k in range(m):
            for l in range(m):
                if a[i + k][j + l] != b[k][l]:
                    flag = False
                    break
        if flag:
            ans = 'Yes'
print(ans)
