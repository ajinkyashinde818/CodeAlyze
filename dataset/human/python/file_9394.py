ma = lambda :map(int,input().split())
ni = lambda:int(input())
import collections
import itertools
import math
n,k = ma()
A  = list(map(lambda x:int(x)-1,input().split()))
vis = [False]*n
cnt = [0]*n
vis[0] = 1
st = 0
c = 0
cyc = 0
l = 0
while True:
    c+=1
    nex = A[st]
    if c==k:
        print(nex+1)
        exit()
    if vis[nex]:
        cyc = cnt[st] - cnt[nex] +1
        l = cnt[st]+1
        break
    cnt[nex] = c
    vis[nex]=True
    st = nex
k = (k-l)%cyc
st = nex
while k>0:
    nex = A[st]
    st = nex
    k-=1
print(nex+1)
