import sys


def input():
    return sys.stdin.readline().strip()


N, M = map(int, input().split())
str_N = str(N)
g = {str(i): set() for i in range(1, N + 1)}
for _ in range(M):
    A, B = input().split()
    if A == '1' or B == str_N:
        g[A].add(B)
        g[B].add(A)

if g['1'].intersection(g[str_N]):
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
