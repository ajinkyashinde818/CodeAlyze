import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())), dtype='int64')
am = a[np.where(a<=0)]

a2 = np.array(list(map(abs, a)), dtype='int64')
ans = sum(a2)
if len(am) % 2 == 1:
    m = np.amin(a2)
    ans -= 2 * m

print(ans)
