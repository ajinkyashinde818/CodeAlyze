import numpy as np
n,m = map(int,input().split())
A1 = np.zeros(n,dtype=bool)
Ai = np.zeros(n,dtype=bool)
for i in range(m):
    a,b = map(int,input().split())
    if a == 1:
        A1[b-1] = True
    if b == n:
        Ai[a-1] = True
if np.any(Ai[A1]):
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
