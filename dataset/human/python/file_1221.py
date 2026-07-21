n = int(input())
A = list(map(int,input().split()))
from itertools import accumulate

A = list(accumulate(A))
ans = float('inf')
for i in range(n-1):
  ans = min(ans, abs((A[-1] - A[i])-A[i]))
print(ans)
