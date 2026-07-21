import sys
N, K = map(int, input().split())
A = list(map(int, sys.stdin.readline().split()))
visited = [0] * N
visited[0] = 1
ikisaki = 0
c = 1
while c < N:
    ikisaki = A[ikisaki] - 1
    c += 1
    if visited[ikisaki]:
        loop = c - visited[ikisaki]
        c = N
    else:
        visited[ikisaki] = c

if K - (visited[ikisaki] - 1) >= 0:
    amari = (K - (visited[ikisaki] - 1)) % loop
else:
    amari = K - (visited[ikisaki] - 1)
new = [i - visited[ikisaki] for i in visited]
print(new.index(amari) + 1)
