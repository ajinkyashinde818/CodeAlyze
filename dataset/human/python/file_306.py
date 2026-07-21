import numpy as np
n = int(input())
A = list(map(int,input().split()))
a = np.abs(A)
mainasu = 0

for i in range(n):
  if A[i]<0:
    mainasu += 1

if mainasu%2 == 0:
  ans = sum(a)
else:
  a = sorted(a)
  ans = sum(a[1:n]) - a[0]
  
print(ans)
