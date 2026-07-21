from itertools import accumulate
MOD = 10 ** 9 + 7
N = int(input())
Xs = list(map(int, input().split()))
Ds = []
for i in range(1, N):
    Ds.append(Xs[i] - Xs[i-1])
S = list(accumulate(Xs))

factorials = [1]
for i in range(1, N):
    factorials.append(factorials[-1]*i % MOD)

def div(a, b):
    return a * pow(b, MOD-2, MOD)

ans = 0
prev = 0
fact = factorials[N-1]
for i, d in enumerate(Ds):
    n = i+1
    tmp = prev + div(fact, n)
    prev = tmp
    ans += tmp * Ds[i]
    ans %= MOD

print(ans)
