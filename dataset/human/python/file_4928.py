import itertools
mod = 10**9 + 7
stdin = [int(_) for _ in open(0).read().split()]
N, X = stdin[0], stdin[1:]
A = [pow(i, mod - 2, mod) for i in range(N)]
D = [0] + [a - b for a, b in zip(X[1:], X[:-1])]
f = 1
for i in range(1, N):
    f *= i
    f %= mod
A = [d * f * a % mod for d, a in zip(D, list(itertools.accumulate(A)))]
print(sum(A) % mod)
