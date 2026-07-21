from collections import Counter
from bisect import bisect_left

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
CA = Counter(A)
CB = Counter(B)

for key, value in CB.items():
    if value + CA[key] > N:
        print('No')
        exit()

C = [0] * (N+1)
D = [0] * (N+1)

for i in range(N):
    C[i + 1] += C[i] + CA[i + 1]
    D[i + 1] += D[i] + CB[i + 1]

x = 0

for i in range(N):
    x = max(x, C[i + 1] - D[i])

ans = [B[(i - x) % N] for i in range(N)]

print('Yes')
print(*ans)
