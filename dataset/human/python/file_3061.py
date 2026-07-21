def primes(N):
    p = [False, False] + [True] * (N - 1)
    for i in range(2, int(N ** 0.5) + 1):
        if p[i]:
            for j in range(i * 2, N + 1, i):
                p[j] = False
    return [i for i in range(N + 1) if p[i]]


def prime_factors(N):
    ret = {}
    for p in primes(int(N ** 0.5) + 1):
        while N % p == 0:
            ret[p] = ret.get(p, 0) + 1
            N //= p
    if N > 1:
        ret[N] = ret.get(N, 0) + 1
    return ret


N = int(input())
ans, ps = 0, prime_factors(N)
for p in ps:
    d = 1
    while ps[p] >= d:
        ps[p] = ps[p] - d
        d += 1
        ans += 1
print(ans)
