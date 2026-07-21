import sys
sys.setrecursionlimit(10**7) #再帰回数の上限を変更
from collections import deque

N,K=map(int,input().split())
A=list(map(int,input().split()))

L=[]
chk=[0 for _ in range(N)]
tmp=0
while(1):
    if chk[tmp]==1:
        break
    chk[tmp]=1
    L.append(tmp)
    tmp=A[tmp]-1
#print(L)
loop_s=A[L[-1]]-1
loop_g=L[-1]
one_to_s=0
tmp=0
#print(loop_s)
#print(loop_g)

while(1):
    if tmp==loop_s:
        break
    tmp=A[tmp]-1
    #print(tmp)
    one_to_s+=1

loop_l=0
tmp=loop_s
Loop=[loop_s]
while(1):
    if tmp==loop_g:
        break
    tmp=A[tmp]-1
    Loop.append(tmp)
    loop_l+=1
loop_l+=1
#print(one_to_s)
if K<=one_to_s:
    tmp=0
    #print("ON")
    cnt=0
    while(1):
        if cnt==K:
            break
        tmp=A[tmp]-1
        cnt+=1
    ans=tmp + 1
else:
    K-=one_to_s
    num=K%loop_l
    ans=Loop[num]+1

print(ans)
