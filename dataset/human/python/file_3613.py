import sys

stdin = sys.stdin
inf = 1 << 60
mod = 1000000007

sys.setrecursionlimit(10**7)

ni = lambda: int(ns())
nin = lambda y: [ni() for _ in range(y)]
na = lambda: list(map(int, stdin.readline().split()))
nan = lambda y: [na() for _ in range(y)]
nf = lambda: float(ns())
nfn = lambda y: [nf() for _ in range(y)]
nfa = lambda: list(map(float, stdin.readline().split()))
nfan = lambda y: [nfa() for _ in range(y)]
ns = lambda: stdin.readline().rstrip()
nsn = lambda y: [ns() for _ in range(y)]
ncl = lambda y: [list(ns()) for _ in range(y)]
nas = lambda: stdin.readline().split()

n = ni()

def prime_factorization(n):
    i = 2
    res = []
    while i * i <= n:
        if n % i != 0:
            i += 1
            continue
        ex = 0
        while n % i == 0:
            ex += 1
            n //= i
        res.append((i, ex))
    if n != 1:
        res.append((n, 1))
    return res

ans = 0
fac = prime_factorization(n)
for a, ex in fac:
    i = 1
    while ex - i >= 0:
        ans += 1
        ex -= i
        i += 1

print(ans)
