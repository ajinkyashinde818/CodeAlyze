import numpy as np

val = input().split(' ')
k = int(val[0])
n = int(val[1])

alist = sorted([int(a) for a in input().split(' ')])

a2list = list(map(lambda a: a + k, alist))
alist.extend(a2list[:-1])
adiff = np.diff(alist)
before = sum(adiff[0: n-1])
result = before
for i in range(1, n):
    tmp = before - adiff[i - 1] + adiff[i - 2 + n]
    before = tmp
    if tmp < result:
        result = tmp
print(result)
