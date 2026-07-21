from collections import deque
S=deque(input())
Q=int(input())
r=1
for i in range(Q):
    T=input().split()
    if T[0]=="1":
        r*=-1
        continue
    t=T[2]
    if T[1]=="1":
        if r==1:
            S.appendleft(t)
        else:
            S.append(t)
        continue
    if r==1:
        S.append(t)
    else:
        S.appendleft(t)
if r==1:
    print("".join(list(S)))
else:
    S.reverse()
    print("".join(list(S)))
