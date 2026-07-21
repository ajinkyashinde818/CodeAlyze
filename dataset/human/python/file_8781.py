import numpy as np
from collections import deque
k,n=map(int,input().split())
lst=np.fromstring(input(),int,sep=' ')
dis=[]
for i in range(1,n):
    dis.append(lst[i]-lst[i-1])
print(k-max(k-lst[-1]+lst[0],max(dis)))
