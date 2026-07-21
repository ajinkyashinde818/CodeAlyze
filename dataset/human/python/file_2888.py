import sys, io, os, re
import bisect
from pprint import pprint
from math import sin, cos, pi, radians, sqrt, floor
from copy import copy, deepcopy
from collections import deque
from fractions import gcd
from functools import reduce

def array1(n): return [0] * n
def array2(n, m): return [[0] * m for x in range(n)]
def array3(n, m, l): return [[[0] * l for y in xrange(m)] for x in xrange(n)]

N = int(sys.stdin.readline().strip())

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

if N == 1:
    print(0)
    exit(0)

e = factorization(N)
#print(e)

ans = 0
for p, q in e:
    c = 0
    j = 1
    while c+j <= q:
        c += j
        j += 1

    ans += (j-1)
    #print(j-1)

print(ans)
