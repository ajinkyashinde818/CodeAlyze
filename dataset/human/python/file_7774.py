import sys
import numpy as np
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

N, K, S = map(int, read().split())

if S != 1:
    ans = [S - 1] * N
else:
    ans = [S + 1] * N
for i in range(K):
    ans[i] = S

print(*ans)
