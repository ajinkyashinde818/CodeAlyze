import numpy as np
k, n = map(int, input().split())
a = np.array(list(map(int, input().strip().split())))
d = np.zeros(n,dtype=np.int64)
d[1:] = a[1:] - a[:-1]
d[0] = a[0] + (k-a[-1])

#print(d)
m = 10**9
q = d[0:-1].sum()
for i in range(n):
    if i == 0:
        q = d[1:].sum()
    else:
        q = q + d[i-1] - d[i]

    if q < m:
        m = q

print(m)
