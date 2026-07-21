from heapq import *
import sys
from collections import *
from itertools import *
from decimal import *
import copy
from bisect import *
import math
sys.setrecursionlimit(4100000)
def gcd(a,b):
    if(a%b==0):return(b)
    return (gcd(b,a%b))
input=lambda :sys.stdin.readline().rstrip()
N,K=map(int,input().split())
A=list(map(int,input().split()))
for i in range(N):
    A[i]-=1
s=0
x=1
visited=[-1 for i in range(N)]
visited[0]=1
flg=0
while K:
    #print(s,K)
    a=A[s]
    x+=1
    if flg:
        K-=1
        s=a
    elif visited[a]==-1:
        K-=1

        visited[a]=x
        s=a
    else:
        #print(x,visited[s])
        K%=x-visited[a]
        flg=1
print(s+1)
