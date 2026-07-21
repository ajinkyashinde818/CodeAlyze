import sys
input = sys.stdin.readline

N, M = map(int, input().split())
edge1 = []
edgeN = []
for _ in range(M):
    s, n = map(int, input().split())
    if s == 1:
        edge1.append(n)
    elif n == N:
        edgeN.append(s)
if len(set(edge1) & set(edgeN)) > 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
