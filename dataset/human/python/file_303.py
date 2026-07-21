import numpy as np
n = int(input())
a = np.array([i for i in input().split()]).astype('int64')

for i in range(n-1):
    if a[i] < 0:
        a[i] = -a[i]
        a[i+1] = -a[i+1]
if a[n-1] < 0 :
    i = a[:n-1].argmin()
    if a[i] < -a[n-1]:
        a[i] = -a[i]
        a[n-1] = -a[n-1]
print(np.sum(a))
