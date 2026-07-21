import sys
import math

N = input()
a = map(int, raw_input().split())

X = long(sum(a))

ans = long(sys.maxint + sys.maxint)

x = 0
for i in range(N - 1):
    x += a[i]
    ans = min(ans, math.fabs(X - 2*x))

print long(ans)
