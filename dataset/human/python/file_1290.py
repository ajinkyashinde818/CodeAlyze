from itertools import accumulate
N = int(input())
A = list(map(int,input().split()))
sumA = list(accumulate(A))
maxA = sumA[-1]
ans = 10**18

for i in range(N-1):
  ans = min(ans, abs(maxA-2*sumA[i]))

print(ans)
