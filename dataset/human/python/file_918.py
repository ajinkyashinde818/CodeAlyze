import numpy as np
import sys
input = sys.stdin.buffer.readline
N,C= map(int,input().split())
x, v = np.array([list(map(int,input().split())) for i in [0]*N]).T.astype(np.int64)
INF = 10**15

rx = C - x[::-1]
dx = np.zeros(N+2).astype(np.int64)
dx[N+1] = C
dx[1:-1] = x
dx = np.diff(dx)

cand = []

# not turnaround 
rv = v - dx[:-1]
rc = np.maximum.accumulate(np.cumsum(rv))
best = rc[-1]
cand.append(best)

lv = v[::-1] - dx[::-1][:-1]
lc = np.maximum.accumulate(np.cumsum(lv))
best = lc[-1]
cand.append(best)

# turnaround
first = (rc-x)[:-1] # ->,<-
second = lc[:-1][::-1] # <-
if first.size:
    cand.append(np.max(first+second))

first = (lc-rx)[:-1]
second = rc[:-1][::-1]
if first.size:
    cand.append(np.max(first+second))

cand.append(0)
print(max(cand))
