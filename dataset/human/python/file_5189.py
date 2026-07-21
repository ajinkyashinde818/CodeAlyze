def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
def getArray(intn):
    return [int(input()) for i in range(intn)]
def input():
    return sys.stdin.readline().rstrip()

from collections import defaultdict, deque, Counter
from sys import exit
from decimal import *
import heapq
import math
from fractions import gcd
import copy
from itertools import permutations
from operator import mul
from functools import reduce
from bisect import bisect_left, bisect_right

import sys
sys.setrecursionlimit(1000000000)
mod = 10 ** 9 + 7

from itertools import permutations
from math import factorial, hypot

#############
# Main Code #
#############

N, M = getNM()
dist = [set() for i in range(N)]
for i in range(M):
    a, b = getNM()
    dist[a - 1].add(b - 1)
    dist[b - 1].add(a - 1)

flag = False
for i in list(dist[0]):
    if N - 1 in dist[i]:
        flag = True
print('POSSIBLE' if flag else 'IMPOSSIBLE')
