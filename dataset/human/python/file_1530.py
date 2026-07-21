import numpy as np

N, M = map(int, input().split())

As = np.array([["." for n in range(N)] for nn in range(N)])
for n in range(N):
  As[n,:] = np.array(list(input()))
  
Bs = np.array([["." for n in range(M)] for nn in range(M)])
for m in range(M):
  Bs[m,:] = np.array(list(input()))
  
ok = False
for i in range(N-M+1):
  for j in range(N-M+1):
    if (As[i:i+M,j:j+M] == Bs).all():
      ok = True
      break
if ok:
  print("Yes")
else:
  print("No")
