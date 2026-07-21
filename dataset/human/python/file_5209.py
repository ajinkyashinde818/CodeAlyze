import sys
N, M = map(int, input().split())
m = set()
m2 = set()
for i in range(M):
    a, b = map(int, input().split())
    if a == 1:
        m.add(b)
    if b == N:
        m2.add(a)
for me in m:
    if me in m2:
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')
