import numpy as np
import collections

N=input()
A=list(map(int,input().split()))

a=np.array(A, dtype=np.float64)
asign=np.sign(A)
c = collections.Counter(asign)
ar = np.array(c[-1], dtype=np.float64)
ac = a * asign

if c[-1] % 2 == 0:
    print(int(sum(ac)))
else:
    print(int(sum(ac)-min(ac)*2))
