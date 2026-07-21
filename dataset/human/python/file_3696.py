import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = ni()

ans = 0
for v in range(2, n):
    if v*v > n:
        break
    e = 0
    while n % v == 0:
        n //= v
        e += 1
    if e > 0:
        for k in range(1, 10):
            if e >= k:
                e -= k
                ans += 1
            else:
                break
if n > 1:
    ans += 1
print(ans)
