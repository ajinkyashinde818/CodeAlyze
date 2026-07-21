import sys
from collections import *
import heapq
import math
import bisect
from itertools import permutations,accumulate,combinations,product
from fractions import gcd
def input():
    return sys.stdin.readline()[:-1]
mod=pow(10,9)+7

n=input()
keta=len(n)
ans=0

# dp=[[0,1]]
# for i in range(keta):
#     dp.append([float('inf')]*2)
dp0=[float('inf')]*(keta+1)
dp1=[float('inf')]*(keta+1)
dp0[0]=0
# dp[0]=[0,1]
# print(dp)
for i in range(keta):
    s=int(n[-1-i])
    dp0[i+1]=min(dp0[i]+s,dp1[i]+s+1)
    dp1[i+1]=min(dp0[i]+(10-s),dp1[i]+(10-s-1))
# print(dp)
print(min(dp0[-1],dp1[-1]+1))
