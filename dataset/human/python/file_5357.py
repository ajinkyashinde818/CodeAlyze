import sys
stdin = sys.stdin
mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
sa = lambda h: [list(map(int, stdin.readline().split())) for i in range(h)]

n, m = na()
from_one = [0] * n
to_n = [0] * n

for _ in range(m):
    a, b = na()
    if a == 1:
        from_one[b] = 1
    if b == n:
        to_n[a] = 1

p = False
for i, j in zip(from_one, to_n):
    if i == 1 and j ==1:
        print("POSSIBLE")
        p = True
        break
if not p:
    print("IMPOSSIBLE")
