import sys
sys.setrecursionlimit(10 ** 6)


def input():
    return sys.stdin.readline()[:-1]


N, M = map(int, input().split())
from_1 = {}
to_n = {}
for _ in range(M):
    a, b = map(int, input().split())
    if a == 1:
        from_1[b] = True
    elif b == N:
        to_n[a] = True

for key in to_n.keys():
    if key in from_1:
        print('POSSIBLE')
        exit(0)
print('IMPOSSIBLE')
