import numpy as np
N = int(input())
Alist = np.array(list(map(int, input().split())))
Blist = list(map(abs, Alist))
nom = sum(Alist<0)
if nom%2 == 0 :
    ans = sum(Blist)
else :
    ans = sum(Blist) - 2*min(Blist)
print(ans)
