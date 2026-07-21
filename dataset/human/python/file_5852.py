import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = ni()
a = na()
b = na()
c = na()

ans = 0
for i in range(n):
    ans += b[a[i]-1]
    if i > 0 and a[i] - a[i-1] == 1:
        ans += c[a[i]-2]

print(ans)
