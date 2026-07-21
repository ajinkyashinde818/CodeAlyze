import sys

readline = sys.stdin.readline
N, M = map(int, readline().split())
x = set()
y = set()
for _ in range(M):
    a, b = map(int, readline().split())
    if a == 1:
        x.add(b)
    if b == N:
        y.add(a)
print('POSSIBLE' if x & y else 'IMPOSSIBLE')
