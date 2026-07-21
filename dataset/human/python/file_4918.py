import sys
readline = sys.stdin.readline

MOD = 10**9+7
def frac(limit):
    frac = [1]*limit
    for i in range(2,limit):
        frac[i] = i * frac[i-1]%MOD
    fraci = [None]*limit
    fraci[-1] = pow(frac[-1], MOD -2, MOD)
    for i in range(-2, -limit-1, -1):
        fraci[i] = fraci[i+1] * (limit + i + 1) % MOD
    return frac, fraci
frac, fraci = frac(1341398)


MOD = 10**9+7
N = int(readline())
X = list(map(int, readline().split()))

D = [x1 - x0 for x0, x1 in zip(X, X[1:])]

g = [0]*(N+3)
g[1] = 1
for i in range(2, N+3):
    g[i] = (g[i-1] + pow(i, MOD-2, MOD)) % MOD

ans = 0
for i in range(N-1):
    ans = (ans + D[i]*g[i+1])%MOD

print(ans*frac[N-1]%MOD)
