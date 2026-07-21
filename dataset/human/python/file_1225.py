import sys
 
stdin = sys.stdin

mod = 1000000007
inf = 1 << 60
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nan = lambda x: [na() for _ in range(x)]
ns = lambda: stdin.readline().rstrip()
nas = lambda: stdin.readline().split()

n = ni()
a = na()
c = [0] * (n + 1)
for i in range(1, n + 1):
    c[i] = c[i - 1] + a[i - 1]

ans = inf
for i in range(n - 1):
    m = i + 1
    ans = min(ans, abs(c[m] - (c[n] - c[m])))

print(ans)
