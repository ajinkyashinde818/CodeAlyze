import numpy as np

N = int(input())  
A = np.array(input().split(), dtype=np.int64)
B = np.array(input().split(), dtype=np.int64)
C = np.array(input().split(), dtype=np.int64)

ans = np.sum(B)

for i in range(N-1):
    if A[i+1] - A[i] == 1:
        ans += C[A[i]-1]
        
print(int(ans))
