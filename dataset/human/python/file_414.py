import numpy as np
N = int(input())
A = list(map(int, input().split()))
B = A.copy()
B.sort()
C=[]
for i in range(N):
  if B[i]<0:
    C.append(B[i])
  else:
    continue
count = len(C)
if count % 2 == 0:
  B = np.abs(B)
  ans = sum(B)
else:
  B = np.abs(B)
  X = sum(B)
  ans = X - 2*min(B)
print(ans)
