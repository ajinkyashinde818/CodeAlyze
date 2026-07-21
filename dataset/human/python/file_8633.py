from collections import deque
K, N = map(int, input().split())
S=deque(list(map(int, input().split())))
ans = [S[-1] - S[0]]
for i in range(N-1):
    ans.append(S[i]- S[i+1] + K)
print(min(ans))
