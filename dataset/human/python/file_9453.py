import sys
import math
import fractions
from collections import deque
from collections import defaultdict
sys.setrecursionlimit(10**7)

N, K = map(int, input().split())
A = list(map(int, input().split()))

for i in range(N):
    A[i] -= 1

visited = set()
visited.add(0)
trace = []
cur = 0
while True:
    trace.append(cur)
    if A[cur] in visited:
        cur = A[cur]
        break
    visited.add(A[cur])
    cur = A[cur]

pre = 0
for i, a in enumerate(trace):
    if a == cur:
        pre = i

loop = len(trace) - pre

if K <= pre:
    ans = trace[K]
else:
    if loop == 0:
        ans = trace[pre::][0]
    else:
        r = (K - pre) % loop
        ans = trace[pre::][r]

print(ans + 1)
