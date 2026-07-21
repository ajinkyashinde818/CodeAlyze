import sys
import numpy as np

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, M = lr()
E = {i+1: set() for i in range(N)}
first = set()
for m in range(M):
    a, b = lr()
    if b == N:
        first.add(a)
    E[a].add(b)
if not first.isdisjoint(E[1]):
    print("POSSIBLE")
    exit(0)
print("IMPOSSIBLE")
