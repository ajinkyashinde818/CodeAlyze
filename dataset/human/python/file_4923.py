MOD = 10 ** 9 + 7


def prepare(n):
    global MOD
    modFacts = [0] * (n + 1)
    modFacts[0] = 1
    for i in range(n):
        modFacts[i + 1] = (modFacts[i] * (i + 1)) % MOD

    invs = [1] * (n + 1)
    invs[n] = pow(modFacts[n], MOD - 2, MOD)
    for i in range(n, 1, -1):
        invs[i - 1] = (invs[i] * i) % MOD

    return modFacts, invs


N = int(input())
X = list(map(int, input().split()))

modFacts, invs = prepare(N)

ans = 0
var = modFacts[N - 1]
p = 0
for i in range(N - 1):
    j = i + 1
    d = X[i + 1] - X[i]
    p += modFacts[N - 1] * modFacts[j - 1] * invs[j]
    ans += (d * p) % MOD
    ans %= MOD

print(ans)
