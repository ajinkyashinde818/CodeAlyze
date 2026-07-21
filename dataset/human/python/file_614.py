N = int(input())
import numpy as np
li = np.array(list(map(int,input().split())))	#1 2 3 4 5 ... n  li=[1,2,3,4,5,...,n]
li_abs = abs(li)
M = np.argmin(li_abs)
if sum(li < 0)%2 == 0:
    print(sum(li_abs))
else:
    for i in range(N-1):
        tmp = N-1-i
        if tmp == M:
            if li[tmp] >= 0:
                li[tmp] = li[tmp] * (-1)
                li[tmp - 1] = li[tmp - 1] * (-1)
        else:
            if li[tmp] < 0:
                li[tmp] = li[tmp]*(-1)
                li[tmp-1] = li[tmp-1]*(-1)

    print(sum(li))
