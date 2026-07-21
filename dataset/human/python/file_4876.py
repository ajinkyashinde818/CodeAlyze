import sys
import  math
from statistics import *
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

s = input()
t = input()
s = sorted(list(s))
t = sorted(list(t), reverse=True)
if s < t:
    print('Yes')
else:
    print('No')
