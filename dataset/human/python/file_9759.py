import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))


n, k = map(int, input().split())
a = list(map(int, input().split()))
a = [item-1 for item in a]

seen = [None] * n
c = 0
val = 0
seen[c] = val
val2c = {}
while True:
    val2c[val] = c
    if seen[a[c]] is not None:
        span = val - seen[a[c]] + 1
        init = seen[a[c]]
        break
    c = a[c]
    val += 1
    seen[c] = val

if k<=init:
    ans = val2c[k]
else:
    ans = val2c[(k-init)%span+init]
print(ans+1)
