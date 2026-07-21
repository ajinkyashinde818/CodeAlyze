import numpy as np
from functools import *
import sys
sys.setrecursionlimit(100000)



def acinput():
    return list(map(int, input().split(" ")))


def II():
    return int(input())

K,N=acinput()

A=acinput()
A.append(A[0]+K)
B=np.array(A)+K
#A.extend(B)
a=np.array(A)

print(K-np.max(a[1:]-a[:-1]))
