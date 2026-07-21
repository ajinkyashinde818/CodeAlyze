import numpy as np
n=int(input())
a=np.array(list(map(int,input().split())))
ans=sum(np.abs(a))
if 0 in a:
    print(ans)
else:
    b=np.where(a<0)
    if np.size(b)%2==0:
        print(ans)
    else:
        ans-=2*min(np.abs(a))
        print(ans)
