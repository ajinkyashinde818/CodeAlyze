import numpy as np
from math import factorial
MOD = 10**9 + 7

n = int(input())

dist = np.diff(list(map(int, input().split())))
L = np.cumsum(np.array([1 / x for x in range(1, n)]))
n_1 = factorial(n-1) % MOD

# fac = [1] * n
# for i in range(1,n):
# 	fac[i] = fac[i-1] * i % MOD

# print(int(np.sum(L * dist * n_1)) % MOD)
# ans = 0
# for l, d in zip(L, dist):
#     print("l d ", l * d)
#     ans += l * d
#     ans %= MOD

ans = 0
tmp = 0
for i, d in enumerate(dist):
    tmp += pow(i+1, MOD-2, MOD)
    ans += tmp * d
    ans %= MOD

# print(n_1)
print(ans * n_1 % MOD)
# print(int(np.sum(dist * L * n_1) % MOD))
