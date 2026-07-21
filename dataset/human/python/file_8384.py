import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

K, n = na()
a = na()

md = 0
for i in range(n-1):
    md = max(md, a[i+1] - a[i])
md = max(md, a[0] + K - a[-1])
print(K - md)
