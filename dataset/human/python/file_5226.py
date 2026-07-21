import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
MOD = 10 ** 9 + 7

N, M = map(int, input().split())

G = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

for i in G[1]:
    for j in G[i]:
        if j == N:
            print ('POSSIBLE')
            exit()

print ('IMPOSSIBLE')
