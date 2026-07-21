import sys


def prepare(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv

    return factorials, invs


n = int(input())
xxx = list(map(int, input().split()))
MOD = 10 ** 9 + 7
factorials, invs = prepare(n, MOD)

ans = 0
dp = 1
for i in range(n - 1):
    cur = dp * factorials[i] % MOD
    ans = (ans + (xxx[i + 1] - xxx[i]) * cur * invs[i + 1]) % MOD
    dp = (dp + (cur + factorials[i + 1]) * invs[i + 1]) % MOD
ans = ans * factorials[n - 1] % MOD
print(ans)
