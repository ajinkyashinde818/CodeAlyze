import numpy as np
from functools import *
import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline


import numpy as np

def acinput():
    return list(map(int, input().split(" ")))

    
def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct



s=factorize(float(input()))

res=0

for ss,n in s:
    tmp=np.floor((np.sqrt(8*n+1)-1)/2)
    #print(tmp)
    res+=tmp

print(int(np.floor(res)))

#print(s)
