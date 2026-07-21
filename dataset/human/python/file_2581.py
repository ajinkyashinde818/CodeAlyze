import sys
from itertools import *
from math import *
input=sys.stdin.readline
D, G = map(int, input().split())
probs = [list(map(int, input().split())) for _ in range(D)]
G2 = G
seq = tuple(range(D))
x=[]
for i in range(0,D+1):
    l=combinations(seq,i)
    for j in l:
        x.append(j)
x=tuple(x)
#print(x)
infty=100000
#print(x)
ans = infty
for cand in x:
    cnt = 0
    G=G2
    l=[0]*D
    for ind in cand:
        probpoint = (ind + 1) * 100
        G=G-(probpoint * probs[ind][0]+probs[ind][1])
        cnt = cnt + probs[ind][0]
        l[ind]=1
    #print(l,G,cnt)
    for i in range(D-1,-1,-1):
        if G<=0:
            break
        elif l[i]==0:
            probpoint = (i + 1) * 100
            num=ceil(G/probpoint)
            if num<probs[i][0]:
                G=G-num*probpoint
                cnt=cnt+num
            #print(cnt)
            break
    if G<=0:
        ans=min(ans,cnt)
print(ans)
