import numpy as np
n,m =map(int,input().split())


A = np.array([list(input()) for i in range(n)])
B = np.array([list(input()) for i in range(m)])
P = np.zeros(B.shape,str)
a = 0
for i in range(n-m+1):
   for j in range(n-m+1):
      P= A[i:i+m,j:j+m]
      if np.all(B==P):
         a = 1
         break

if a ==0:
   print("No")
else:
   print("Yes")
