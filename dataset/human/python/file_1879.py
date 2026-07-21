import numpy as np
import sys
temp = input().split()
N = int(temp[0])
M = int(temp[1])
A = []
B = []
check = False
def change(n):
  if(n=='#'):
    return True;
  return False;

for i in range(N):
  temp = input()
  A.append(list(map(change, temp)))
for i in range(M):
  temp = input()
  B.append(list(map(change, temp)))
A = np.array(A)
B = np.array(B)

for i in range(N-M+1):
  for j in range(N-M+1):
    if (B== A[i:M+i, j:M+j]).all():
      check = True
      break
  if check:
    break

if check:
  print("Yes")
else:
  print("No")
