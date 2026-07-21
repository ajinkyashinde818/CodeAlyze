import math
N = int(input())
x = list(map(int, input().split()))
kyori = [x[i + 1] - x[i] for i in range(N - 1)]
MOD = 10 ** 9 + 7
kai = [0] * (N + 1)
kai[0] = 1
for i in range(1, N + 1):
    kai[i] = (kai[i - 1] * i) % MOD
c = [0] * N
c[0] = 0
for i in range(1, N):
    c[i] = ((kai[N - 1] * pow(i, MOD - 2, MOD) % MOD) + c[i - 1]) % MOD
ans = 0
for i in range(N - 1):
    ans = (ans + kyori[i] * c[i + 1] % MOD) % MOD

print(ans)
