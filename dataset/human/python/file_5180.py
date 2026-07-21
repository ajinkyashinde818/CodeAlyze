import sys
input = sys.stdin.readline
N, M = map(int, input().split())
a = []
b = []
for _ in range(M):
    X, Y = map(int, input().split())
    if X == 1:
        a.append(Y)
    if Y == 1:
        a.append(X)
    if X == N:
        b.append(Y)
    if Y == N:
        b.append(X)
if len(set(a) & set(b)) == 0:
    print('IMPOSSIBLE')
else:
    print('POSSIBLE')
