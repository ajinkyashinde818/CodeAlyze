from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))
B = list(accumulate(A))
S = B[-1]

ans = float('inf')
for i in range(N-1):
  x = B[i]
  y = S - x
  ans = min(ans, abs(x - y))

print(ans)
