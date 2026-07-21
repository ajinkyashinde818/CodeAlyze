from collections import deque
S=deque(input())
Q=int(input())
h=0
for i in range(Q):
    q=input().split()
    if q[0]=="1":
        h=1-h
    else:
        t=int(q[1])
        if t==h+1:
            S.appendleft(q[2])
        else:
            S.append(q[2])
if h==0:
    for i in S:
        print(i,end="")
else:
    for i in range(len(S)):
        print(S[-i-1],end="")
