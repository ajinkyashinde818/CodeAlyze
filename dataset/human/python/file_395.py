N = int(input())
A = list(map(int,input().split()))
A.sort()
import numpy as np
Ac = A.copy()
Ac.sort(key = lambda x:np.abs(x))

import bisect
zero_idx = bisect.bisect(A,0)
if zero_idx == 0:
    An = []
    Ap = A[:]
elif zero_idx == N:
    Ap = []
    An = A[:]
else:
    An = A[:zero_idx]
    Ap = A[zero_idx:]
    
pnum = len(Ap)
nnum = len(An)
ans = 0
total = 0
for a in A:
    total += int(np.abs(a))

if N%2 == 0:
    if nnum % 2 == 0:
        ans = total
    else:
        ans = total - 2 * np.abs(Ac[0])
           
    
else:
    if nnum % 2 == 1:        
        ans = total - 2 * np.abs(Ac[0])
    else:           
        ans = total
    
    
print(ans)
