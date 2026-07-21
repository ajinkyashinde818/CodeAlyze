import sys
input = sys.stdin.readline
N,M = [int(i) for i in input().split()]
nes = [0] * (N+1)
for i in range(1,N+1) :
    nes[i] = []
for i in range(M) :
    a,b = [int(i) for i in input().split()]
    nes[a].append(b)
    nes[b].append(a)
ans = "IMPOSSIBLE"
for i in nes[1] :
    for j in nes[i] :
        if j == N :
            ans = "POSSIBLE"
            break
print(ans)
