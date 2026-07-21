import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop
import copy
from test.support import _MemoryWatchdog

BIG_NUM = 2000000000
HUGE_NUM = 99999999999999999
MOD = 1000000007
EPS = 0.000000001
sys.setrecursionlimit(100000)


SIZE = 105
table = [0]*SIZE

N = int(input())
input_array = list(map(int,input().split()))

maximum = 0

for i in range(N):
    table[0] -= 1
    table[input_array[i]] += 1
    maximum = max(maximum,input_array[i])

for i in range(maximum-1,-1,-1):
    table[i] += table[i+1]

ans = 0

for i in range(1,maximum+1):
    if i <= table[i]:
        ans = i

print("%d"%(ans))
