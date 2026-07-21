import numpy as np
N = int(input())
A = list(map(int,input().split()))
A = np.array(A).astype(np.int64)
odd_even = np.sum(A<0) %2
absA = np.abs(A)
abssum = np.sum(absA)
if odd_even==1:

    ans = abssum - 2 * np.sort(absA)[0]
else:
    ans  = abssum
print(ans)
