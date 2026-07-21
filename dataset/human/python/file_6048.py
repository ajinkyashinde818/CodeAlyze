import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()
b = na()
c = na()

t = -2
ans = 0
for i in a:
    ans += b[i-1]
    if t+1 == i:
        ans += c[i-2]
    t = i

print(ans)
