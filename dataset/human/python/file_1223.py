import math
ans = math.inf
n = int(input())
c = list(map(int, input().split()))
acm = [0]*(n+1)
for i, v in enumerate(c, 1):
    acm[i] += acm[i-1] + v

s, a = 0, acm[n]
for i in range(1, n):
    s = acm[i]
    ans = min(ans, abs((a-s)-s))

print(ans)
