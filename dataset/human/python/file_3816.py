from sys import stdin
from copy import deepcopy
from functools import reduce
from fractions import gcd
import math
import itertools
from collections import Counter
from itertools import chain  ##list(chain.from_iterable(l)) ##flatten
from heapq import heappush, heappop
import bisect

"""
N = int(input())
A, B = map(int,input().split())
A = list(map(int,input().split())) ## 横一列
A = [int(input()) for _ in range(N)] ## 縦一列
lst = [list(map(int,input().split())) for i in range(M)] ## 二次元
"""

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
  

  

N = int(input())  

if N == 1:
  print(0)
  exit()

div = factorization(N)
#print(div)

ans = 0
for i in range(len(div)):
  x = div[i][1]
  var = int((-1 + math.sqrt(1 + 8*x)) / 2)
  ans += var
  #print(x, var)
  

print(ans)
