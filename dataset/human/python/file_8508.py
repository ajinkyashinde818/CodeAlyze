import numpy as np

k,n = map(int, input().split())

a = np.array(list(map(int, input().split())))
a.sort()

dif = np.diff(a, n=1)
maximum = max(dif.max(), a[0]+(k-a[-1]))

print(k-maximum)
