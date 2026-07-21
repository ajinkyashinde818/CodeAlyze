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

x, y = ns().split()
if x < y:
    print('<')
elif x == y:
    print("=")
else:
    print(">")
