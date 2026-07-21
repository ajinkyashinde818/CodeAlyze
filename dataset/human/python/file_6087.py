import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()

n = ni()
aaa = na()
bbb = na()
ccc = na()
ans = 0
pr = -100
for i in range(n):
    a = aaa[i] - 1
    ans += bbb[a]
    if a == pr + 1:
        ans += ccc[pr]
    pr = a

print(ans)
