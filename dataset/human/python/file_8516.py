import numpy as np

k,n = map(int,input().split())
A = list(map(int, input().split()))
A = np.array(A)
B = np.diff(A, n=1)

B_ = (A[0])+(k-A[n-1])
B_ans = np.append(B,B_)
ans = np.argmax(B_ans)

print(k - B_ans[ans])
