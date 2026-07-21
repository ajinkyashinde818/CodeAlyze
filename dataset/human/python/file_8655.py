import numpy as np

N,K=map(int,input().split())
A=list(map(int,input().split()))
arr = np.array(A)
diff = np.diff(arr)

start_to_end=A[0]+N-A[K-1]

if max(diff) < start_to_end:
    print(sum(diff))
else:
    print(sum(diff)-max(diff)+start_to_end)
