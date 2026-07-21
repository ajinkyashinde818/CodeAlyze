import sys

N=int(input())
A=list(map(int,input().split()))
L=[0]*(N+1)
ans=sys.maxsize

for i in range(N):
  L[i+1]=L[i]+A[i]

for i in range(1,N):
  x = L[i]
  y = L[-1] - L[i]
  if ans >= abs(x-y):
    ans = abs(x-y)
print(ans)
