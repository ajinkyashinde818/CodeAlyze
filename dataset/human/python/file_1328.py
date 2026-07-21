N = int(input())
A = list(map(int, input().split()))

from operator import add
from itertools import accumulate

L = list(accumulate(A, add))

ans = float("inf")
for i in range(N-1):
  x = L[i]
  y = L[N-1] - L[i]
  ans = min(ans, abs(x-y))

print(ans)
