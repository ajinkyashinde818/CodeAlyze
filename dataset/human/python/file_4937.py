from math import factorial

mod = 10**9+7
N = int(input())
x = [0] + list(map(int, input().split()))
ans = 0
inv = [0] + [pow(i, mod-2, mod) for i in range(1, N)]

for k in range(2, N):
    ans = (ans + x[k] * (1 - inv[k])) % mod

for k in range(1, N-1):
    ans = (ans - x[k] * (1 - inv[N-k])) % mod

for k in range(1, N):
    ans = (ans + (x[N] - x[k]) * inv[N-k]) % mod

ans = ans * factorial(N-1) % mod

print(ans)
