from collections import deque

S=deque(list(input()))
Q=int(input())

kkk=1
for i in range(Q):
    Query=list(input().split())
    if Query[0]=="1":
        kkk*=-1
    else:
        num,F,C=Query
        if F=="1":
            if kkk==1:
                S.appendleft(C)
            else:
                S.append(C)
        else:
            if kkk==-1:
                S.appendleft(C)
            else:
                S.append(C)
S=list(S)
if kkk==-1:
    print("".join(S[::-1]))
else:
    print("".join(S))
