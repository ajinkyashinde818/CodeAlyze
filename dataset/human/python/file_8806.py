import sys
import math
import fractions
from collections import deque
from collections import defaultdict
sys.setrecursionlimit(10**7)

K, N = map(int, input().split(' '))
A = list(map(int, input().split(' ')))
diffs = []
prev = 0
for a in A:
    diffs.append(a - prev)
    prev = a
last = K - A[-1] + A[0]
diffs.append(last)

print(K - max(diffs))
