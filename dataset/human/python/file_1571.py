n,m = list(map(int,input().split()))
import numpy as np
A = np.zeros([n,n]).astype(np.int)
B = np.zeros([m,m]).astype(np.int)
for i in range(n):
    A[i,:] = [1 if s == '#' else 0 for s in input()]
for i in range(m):
    B[i,:] = [1 if s == '#' else 0 for s in input()]
# print(A)
# print("---")
# print(B)
# print("---")

ans = 0
for i in range(0,n-m+1):
    for j in range(0,n-m+1):
        if (A[i:i+m,j:j+m] == B).all():
            ans = 1
            break

if ans:
    print("Yes")
else:
    print("No")
