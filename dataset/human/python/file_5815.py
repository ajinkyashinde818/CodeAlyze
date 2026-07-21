import numpy as np

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0
for i, a in enumerate(A):    
    ans += B[a-1]
    
A_ = [-100] + A[:-1]
A_ = np.array(A_)
A = np.array(A)

A_diff = A - A_

for j in A[A_diff == 1] -1:
    ans += C[j-1]
print(ans)
