import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop

BIG_NUM = 2000000000
MOD = 1000000007
EPS = 0.000000001


table = input()

FLG = False

for i in range(len(table)):
    if table[i] == '9':
        FLG = True
        break

if FLG == True:
    print("Yes")
else:
    print("No")
