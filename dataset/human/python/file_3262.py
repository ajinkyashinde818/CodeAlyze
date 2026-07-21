import numpy as np
import math
import copy 

N = np.int64(input())

p = []
x  = 2
xen = np.sqrt(N)
while N > 1 : 
    if N%x == 0 :
        p.append(x)
        N = N/x
    else :
        x = x + 1
        if x > xen :
            p.append(int(N))
            break
e = []
while p!=[]:
    i = p[0]
    n = p.count(i)
    p = p[n:]
    e.append(n)
    if p==[]:break

i = 0
m = 0
e = np.array(e)
ans = 0
while True:
    i += 1
    e = e-i
    e = e[e>=0]
    ans = ans + len(e)
    if len(e)==0 : break

print(ans)
