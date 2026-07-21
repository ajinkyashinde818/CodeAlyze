import sys
sys.setrecursionlimit(10000000)
def input():
    return sys.stdin.readline()[:-1]
from bisect import *
from collections import *
from heapq import *
from math import *
from itertools import *

N = int(input())
A = list(map(int, input().split()))
S, s = sum(A), (N+1)*N//2
if S % s:
    print('NO')
else:
    k = S//s
    B = [A[i+1]-A[i]-k for i in range(N-1)]+[A[0]-A[N-1]-k]
    for b in B:
        if b > 0 or b % N:
            print('NO')
            exit()
    print('YES')
