from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(math.sqrt(n)) + 2):
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

n = int(stdin.readline().rstrip())
a = factorization(n)

m = 0
for b in a:
    bb = b[1]
    i = 0
    while True:
        bb -= i+1
        if bb >= 0:
            i += 1
        else:
            break
    m = m + i

if n != 1: print(m)
if n == 1: print(0)
