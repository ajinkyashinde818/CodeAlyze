import collections
import sys
import numpy as np
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
MOD = 10**9+7
import itertools
import math
import functools

n = input()
for i in range(len(n)):
    if n[i] == "9":
        print("Yes")
        sys.exit()
print("No")
