import numpy as np
k,n=map(int,input().split())
a=list(map(int,input().split()))
a=np.array(a)
a1=abs(a[1:]-a[:-1])
a2=list(a1)
a2.append(abs(a[0]+k-a[-1]))
print(sum(a2)-max(a2))
