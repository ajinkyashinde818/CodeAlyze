import sys

input = sys.stdin.readline

N, K, S = map(int, input().split())
ans = []

large = 1000000000

if S == large:
    for _ in range(K):
        ans.append(S)
    for _ in range(N - K):
        ans.append(1)  
else:
    for _ in range(K):
        ans.append(S)
    for _ in range(N - K):
        ans.append(large)

print(*ans)
