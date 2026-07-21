import sys
K, N = map(int, sys.stdin.readline().split())
A = sorted(list(map(int, sys.stdin.readline().split())))
ans = K
A.append(K + A[0])

for i in range(N):
    d = A[i + 1] - A[i]
    dist = K - d
    ans = min(ans, dist)
print(ans)
