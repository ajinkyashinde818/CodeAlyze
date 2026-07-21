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

n, m = na()
a = nsn(n)
b = nsn(m)

ans = False
for i in range(n):
    for j in range(n):
        if i + m - 1 >= n or j + m - 1 >= n:
            continue
        flag = True
        for k in range(m):
            for l in range(m):
                if a[i + k][j + l] != b[k][l]:
                    flag = False
        if flag:
            ans = True

print("Yes" if ans else "No")
