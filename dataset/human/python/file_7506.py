from collections import deque

S=input()
N=int(input())
inilen=len(S)
d=deque()
for i in range(inilen):
    d.append(S[i])
revflag=False
for i in range(N):
    L=list(map(str,input().split()))
    if L[0]=="1":
        if revflag==False:
            revflag=True
        else:
            revflag=False
    elif L[1]=="1":
        if revflag==False:
            d.appendleft(L[2])
        else:
            d.append(L[2])
        
    elif L[1]=="2":
        if revflag==False:
            d.append(L[2])
        else:
            d.appendleft(L[2])

if revflag==True:
    d.reverse()

Z=list(d)
Z=[str(a) for a in Z]
Z="".join(Z)
print(Z)
