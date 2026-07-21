K,N=map(int,input().split())
A=list(map(int,input().split()))

import numpy as np
A=np.array(A)

ans=max(np.diff(A).max(), K-A[-1]+A[0])
if ans<=K/2:
    print(K-ans)
else:
    print(ans)
