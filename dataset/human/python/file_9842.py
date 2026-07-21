import math
N, K = map(int, input().split())
S = list(map(int, input().split()))
d = [[0]*(N+1) for _ in range(math.ceil(math.log2(K)))]

for i in range(N):
    d[0][i+1] = S[i]

for i in range(1, math.ceil(math.log2(K))):
    for j in range(1, N+1):
        d[i][j] = d[i-1][d[i-1][j]]

ans = 1
for i in range(math.ceil(math.log2(K))):
    if (K >> i)&1:
        ans = d[i][ans]
print(ans)
