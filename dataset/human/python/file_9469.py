import numpy as np
import sys
import math
from collections import defaultdict

N , K = map(int,input().split())
A = list(map(int,input().split()))

ha = defaultdict(int)
ans = defaultdict(int)
s = set()
s.add(1)
ss = set()
mod = 0
mod2 = 0
next = 0
ind = 0
flag = 0
while  True:
    if A[next] in s and flag == 0:
        flag = 1
        ha[0] = A[next]
        ans[0] = A[next]
        ss.add(A[next])
        ind = 0
        mod += 1
        continue
        # next = A[next] - 1 
    elif flag == 1:
        next = A[next] - 1
        ans[ind+1] = A[next]
        mod2 += 1
        if A[next] in ss :
            break
        ss.add(A[next])
        ind += 1
        continue

    ha[ind+1] = A[next]
    s.add(A[next])
    next = A[next] - 1
    mod += 1
    ind += 1

if mod >= K :
    print(ha[K % mod])
else:
    print(ans[(K-mod)%mod2])

#print(ha)
#print(ans)
