import math
import sys
from copy import copy
import numpy as np
from collections import defaultdict, deque, Counter 
from itertools import accumulate, product, permutations,combinations, combinations_with_replacement
from operator import itemgetter
from bisect import bisect_left,bisect
from heapq import heappop,heappush
from fractions import gcd

max_value = 1000000000
min_value = -1000000000
sys.setrecursionlimit(max_value)

n = int(input())
s = list(input())

count = 0


if s[0] == 'W' or s[-1] == 'W':
    print(0)
    sys.exit()

LR_list = ['' for i in range(2*n)]
LR_list[0] = 'L'

for i in range(1,len(LR_list)):
    if s[i] == s[i-1]:
        if LR_list[i-1] == 'R':
            LR_list[i] = 'L'
        else:
            LR_list[i] = 'R'
    else:
        if LR_list[i-1] == 'R':
            LR_list[i] = 'R'
        else:
            LR_list[i] = 'L'

values = []

if LR_list.count('L') != LR_list.count('R'):
    print(0)
    sys.exit()


li = 0
ri = 0
for i in range(len(LR_list)):
    if i != 0:
        if LR_list[i-1] == 'L':
            li += 1
        elif LR_list[i-1] == 'R':
            ri += 1
    if LR_list[i] == 'R':
        values.append(li-ri)
value = 1
for i in range(len(values)):
    value = value * values[i] % (10**9+7)
for i in range(2,n+1):
    value = value * i %(10**9+7)
print(value)
