import sys

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = sum(B)

if N == 2 and A[0] == 1: ## only 2 items, and order 1 to 2
  ans = ans +C[0]
  print(ans)
  sys.exit()

for i in range(1,N):
  if A[i]-A[i-1] == 1:
    ans= ans +C[-1+A[i-1]]

print(ans)
