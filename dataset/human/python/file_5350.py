import sys
input = sys.stdin.readline

N, M = map(int, input().split())
ship1 = set([])
ship2 = set([])
for i in range(M):
    a, b = map(int, input().split())
    if a == 1:
        ship1.add(b)
    elif b == N:
        ship2.add(a)

if ship1 & ship2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
