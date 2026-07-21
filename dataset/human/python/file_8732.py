import numpy as np
import statistics

k,n = map(int,input().split())

a = list(map(int,input().split()))


b = np.array(a)


b = b%k
b.sort()



dis = 0

for i in range(1,n):
    dis = max(dis,abs(b[i]- b[i-1]))

dis = max(dis,(b[0]+k-b[n-1]))


print(k - dis)
