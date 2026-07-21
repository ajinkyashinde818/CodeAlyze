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

s = ns()
n = len(s)

ans = True
while len(s) > 0:
    if s.endswith("dreamer"):
        s = s[:-7]
    elif s.endswith("dream"):
        s = s[:-5]
    elif s.endswith("eraser"):
        s = s[:-6]
    elif s.endswith("erase"):
        s = s[:-5]
    else:
        ans = False
        break

print("YES" if ans else "NO")
