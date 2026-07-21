import numpy as np
N = int(input())
a = list(map(int,input().split()))
tmp = a[0]
S = sum(a)
ans = np.abs(S-2*tmp)
for i in range(1,N-1):
    tmp += a[i]
    ans = min(ans,np.abs(S-2*tmp))
    
print(ans)
