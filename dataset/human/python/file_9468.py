import sys
import itertools
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
 
N, K = map(int, readline().split())
A = list(map(lambda x: x - 1, map(int, readline().split())))
visited = [False for i in range(N)]

cur = 0
cycle = []
start = 0
while True:
    if visited[cur]:
        start = cur + 1
        break

    visited[cur] = True
    cycle.append(cur + 1)
    cur = A[cur]

# print(cycle)
cycle_start_idx = 0
for i in range(len(cycle)):
    if cycle[i] == start:
        cycle_start_idx = i
        break

if K <= cycle_start_idx:
    print(cycle[K])
    exit()


cycle_len = len(cycle) - cycle_start_idx
idx = (K - cycle_start_idx) % cycle_len
print(cycle[idx + cycle_start_idx])
