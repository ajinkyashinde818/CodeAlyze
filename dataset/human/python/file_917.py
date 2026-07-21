import sys
from sys import stdin, stdout
import math
from copy import deepcopy
rem=10**9+7
sys.setrecursionlimit(10 ** 6)
take = lambda: map(int, stdin.readline().split())



n,c=take()
ans=[]
ans2=[]
ans1=[]
ans3=[]
u=[0]
f=[0]
all=[[0,0]]
rev=[[0,0]]
for i in range(n):
    a,b=take()
    all.append([a,b])
    rev.append([c-a,b])
all.sort()
rev.sort()
#print all,rev
tot=0
en=0
for i in all:
    a,b=i
    tot+=b
    en=tot
    ans.append(en-a)
    ans1.append(en-2*a)

tot=0
en=0
for i in rev:
    a,b=i
    tot += b
    en = tot
    ans2.append(en - a)
    ans3.append(en-2*a)

fin=0
#print all,rev
#print ans,ans2
t=0
k=0
for i in range(len(ans)):
    t=max(t,ans[i])
    u.append(t)
    k=max(k,ans2[i])
    f.append(k)

#print ans,ans1,ans2,ans3,f
for i in range(n+1):
    fin=max(fin,ans1[i]+f[n-i+1])
    fin=max(fin,ans3[i]+u[n-i+1])
print fin
