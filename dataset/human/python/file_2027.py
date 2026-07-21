import collections
import numpy as np
aaa = 10 ** 9 + 7
N = int(input())
S =  [s for s in input()]
c = collections.Counter(S)
num = np.array(list(c.values()))
num = num + 1
count = 1
if N == 1:
    print(1)
else:
    for i in num:
        count *= i 
        count = count % aaa 
    print((count - 1))
