import numpy as np
N = int(input())
Alist = list(map(int, input().split())) 
Blist = list(map(abs, Alist))
Blist.sort()
parity = 1
for a in Alist:
    parity = parity*np.sign(a)
if parity>0:
    print(sum(Blist))
else:
    print(sum(Blist[1:])-Blist[0])
