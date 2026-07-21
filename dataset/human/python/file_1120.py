from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from math import gcd
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, gcd
from operator import mul
from functools import reduce


sys.setrecursionlimit(2147483647)
INF = 10 ** 13
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().rstrip().split()
def S(): return sys.stdin.readline().rstrip()
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]

mod=10**9+7

n=I()
A=LI()
B=sorted(LI(),reverse=True)
s=[]
c=0
ret=0
g,h=Counter(A+B).most_common()[0]
if h>n:
    print("No")
    exit()

for i in range(n):
    if A[i]==B[i]:
        ret+=2
        s+=[i]
        c=A[i]



for j in range(n):
    if A[j]!=c and B[j]!=c and s:
        k=s.pop()
        B[k],B[j]=B[j],B[k]

print("Yes")
print(*B)
