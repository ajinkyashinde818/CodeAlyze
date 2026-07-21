from collections import *
from heapq import *
from itertools import *
from fractions import gcd
import sys
from decimal import *
import copy
from bisect import *
input=lambda :sys.stdin.readline().rstrip()


K,N=map(int,input().split())
A=list(map(int,input().split()))

value=10**9
value=min(value,-(A[0]-A[-1]))
for i in range(1,N):
    value=min(value,K-(A[i]-A[i-1]))
    #value=min(value,K-(A[i+1]-A[i]))
print(value)
