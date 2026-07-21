import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, acos, atan, asin, log, log10
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
def debug(*args):
    if debugmode:
        print(*args)
def input(): return sys.stdin.readline().strip()
def STR(): return input()
def INT(): return int(input())
def FLOAT(): return float(input())
def MAP(): return map(int, input().split())
def S_MAP(): return map(str, input().split())
def LIST(): return list(map(int, input().split()))
def S_LIST(): return list(map(str, input().split()))
def lcm(a, b): return a * b // gcd(a, b)
sys.setrecursionlimit(10 ** 9)
inf = sys.maxsize
mod = 10 ** 9 + 7
dx = [0, 0, 1, -1, 1, -1, -1, 1]
dy = [1, -1, 0, 0, 1, -1, 1, -1]
debugmode = False

s = STR()
i = 0
l = len(s)
debug(l)
while i < l:
    debug(i, s[i])
    if i + 4 >= l:
        print('NO')
        exit()
    if s[i] == 'd':
        if s[i:i + 5] != 'dream':
            print('NO')
            exit()
        if i + 5 >= l:
            i += 5
        elif i + 6 == l - 1 and s[i:i + 7] == 'dreamer':
            i += 7
        elif i + 6 < l and s[i:i + 7] == 'dreamer':
            if s[i + 7] == 'a':
                i += 5
            else:
                i += 7
        else:
            i += 5
    elif s[i] == 'e':
        if s[i:i + 5] != 'erase':
            print('NO')
            exit()
        if i + 5 >= l:
            i += 5
        elif i + 5 == l - 1 and s[i:i + 6] == 'eraser':
            i += 6
        elif i + 6 < l and s[i:i + 6] == 'eraser':
            if s[i + 6] == 'a':
                i += 5
            else:
                i += 6
        else:
            i += 5
    else:
        print('NO')
        exit()
print('YES')
