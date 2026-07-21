N = 4010
p = 998244353
mi2 = [0] * N
inv = [0] * N
fac = [0] * N

def C(x, y):
    return fac[x] * inv[y] * inv[x - y] % p

def Calc(n, a, b):
    ans = 0
    for i in range(min(a, n) + 1):
        if i == b == 0:
            continue
        ans += C(a, i) * mi2[i] * C(n + b - 1, n - i) % p
    return ans % p

mi2[0] = fac[0] = inv[0] = inv[1] = 1
for i in range(1, N):
    mi2[i] = mi2[i - 1] * 2 % p
    fac[i] = fac[i - 1] * i % p
for i in range(2, N):
    inv[i] = inv[p % i] * (p - p // i) % p
for i in range(2, N):
    inv[i] = inv[i - 1] * inv[i] % p

k, n = map(int, input().split())
for i in range(2, 2 * k + 1):
    ans = 0
    cnt = min(k, (i - 1) >> 1) - max(i - k, 1) + 1
    if i & 1:
        ans += Calc(n, cnt, k - cnt * 2)
    else:
        ans += Calc(n, cnt, k - cnt * 2 - 1)
        ans += Calc(n - 1, cnt, k - cnt * 2 - 1)
    print(ans % p)
