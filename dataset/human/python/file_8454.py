ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))
import numpy as np

k,n = mi()
a=np.array(li())

b = a[1:] - a[:n-1]
b_max = np.max(b)
c = a[0] + k-a[n-1]

print(k-max(b_max,c))
