mod = 10 ** 9 + 7

def fact(n):
    res = 1
    for i in range(2, n + 1):
        res = (res * i) % mod
    return res


N, *X = map(int, open(0).read().split())

ans = 0
for i in range(N - 1):
    ans += (X[-1] - X[i]) * pow(i + 1, mod - 2, mod)
    ans %= mod

print(ans * fact(N - 1) % mod)
