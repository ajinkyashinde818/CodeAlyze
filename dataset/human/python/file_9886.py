import sys

stdin = sys.stdin
inf = 1 << 60
mod = 1000000007

sys.setrecursionlimit(10 ** 7)

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

n, k = na()
a = na()

dp = [[-1] * (n + 1) for _ in range(61)]
for i in range(n):
    dp[0][i] = a[i] - 1
for i in range(60):
    for j in range(n):
        dp[i + 1][j] = dp[i][dp[i][j]]

cur = 0
for i in range(60, -1, -1):
    if k & (1 << i):
        cur = dp[i][cur]

print(cur + 1)
