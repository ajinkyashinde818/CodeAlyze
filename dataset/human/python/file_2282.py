import sys
stdin = sys.stdin
inf = 1 << 60
mod = 1000000007
 
ni      = lambda: int(ns())
nin     = lambda y: [ni() for _ in range(y)]
na      = lambda: list(map(int, stdin.readline().split()))
nan     = lambda y: [na() for _ in range(y)]
nf      = lambda: float(ns())
nfn     = lambda y: [nf() for _ in range(y)]
nfa     = lambda: list(map(float, stdin.readline().split()))
nfan    = lambda y: [nfa() for _ in range(y)]
ns      = lambda: stdin.readline().rstrip()
nsn     = lambda y: [ns() for _ in range(y)]
ncl     = lambda y: [list(ns()) for _ in range(y)]
nas     = lambda: stdin.readline().split()

from math import ceil

d, g = na()
pc = nan(d)

ans = inf
for i in range(2 ** d):
    cur = g
    cnt = 0
    for j in range(d - 1, -1, -1):
        p, c = pc[j]
        if i >> j & 1:
            score = (j + 1) * 100 * p + c
            if score < cur:
                cur -= score
                cnt += p
            else:
                cnt += min(p, cur // ((j + 1) * 100))
                cur = 0
                break
    if cnt != 0 and cur == 0:
        ans = min(ans, cnt)

print(ans)
