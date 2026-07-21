import sys
input = sys.stdin.readline
import numpy as np
from decimal import *

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


n = int(input())
if n == 1:
    print(0)
else:
    arr = factorization(n)

    arr = np.array(arr)

    kazu = arr[:,1]
    sum = 0
    for i in range(1, 1000000):
        if len(kazu) ==0:
            break
        sum += len(kazu)
        kazu -= (i)
        tugi =[]
        for k in kazu:
            if k < 0:
                sum -=1
                pass
            elif k == 0:
                pass
            else:
                tugi.append(k)
        kazu = np.array(tugi)
    print(sum)
