import numpy as np
N = int(input())
a = np.array(list(map(int,input().split())))
b = a[a<0]
if len(b)%2==0:
    print(int(sum(np.abs(a))))
else:
    print(int(sum(np.abs(a))-2*min(np.abs(a))))
