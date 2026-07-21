import numpy as np
N =int(raw_input())
A =map(int ,raw_input().split())
B =np.abs(A)
B = np.array(B,dtype=np.int64)
C = min(B)
D = (sum(B))
E = D - 2*C
k = 0
for i in range(N):
    if A[i]<0:
        k = k+1
if k%2 == 0:
    print D
else:
    print E
