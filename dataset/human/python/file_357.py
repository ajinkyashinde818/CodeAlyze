import numpy as np
n = int(input())
a = [int(i) for i in input().split()]
a = np.array(a, dtype='int64')
k = np.sum(a < 0)
a = np.absolute(a)
a.dtype ='uint64'
a.sort()

if k % 2 == 0:
    print(int(np.sum(a)))
else :
    print(int(np.sum(a)- a[0]*2))
