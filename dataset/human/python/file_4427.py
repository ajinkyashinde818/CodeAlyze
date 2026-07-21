import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()

res = []
x = n
y = 2
while y*y <= x:
    while x % y == 0:
        res.append(y)
        x //= y
    y += 1
if x > 1:
    res.append(x)

from collections import Counter
import bisect

c = Counter(res)

tt = [i for i in range(1,60)]
for j in range(1,len(tt)):
    tt[j] += tt[j-1]

ans = 0
for v in c.values():
    ans += bisect.bisect_right(tt,v)

print(ans)
