import sys
input = sys.stdin.readline

n, m = map(int, input().split())
ships = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    ships[a-1].append(b-1)
    ships[b-1].append(a-1)

if set(ships[0]) & set(ships[-1]) == set():
    print('IMPOSSIBLE')
else:
    print('POSSIBLE')
