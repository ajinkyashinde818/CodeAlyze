n = int(input())
x = list(map(int, input().split()))

x_diff = []
for i in range(n-1):
    x_diff.append(x[i+1] - x[i])



def modinv(a, mod=10**9+7):
    return pow(a, mod-2, mod)

base = 1
for i in range(1, n):
    base *= i
    base %= 10**9+7

frac = []
for i in range(1, n):
    frac.append(base*modinv(i) % (10**9+7))

import itertools
frac = list(itertools.accumulate(frac))

ans = 0
for i in range(n-1):
    ans += frac[i]*x_diff[i]
    ans %= 10**9+7

print(ans)
