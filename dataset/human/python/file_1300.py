from math import ceil
from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(_) for _ in stdin.readline().rstrip().split()]
Asum = sum(A)
ans = 10**10
x = 0
for i in range(N-1):
    x+=A[i]
    ans = min(ans, abs(Asum-2*x))
print(ans)
