from queue import deque
S=deque(input())
Q=int(input())
s=0
for i in range(Q):
    q=list(input().split())
    if int(q[0])==1:
        if s==0:
            s=1
        else:
            s=0
    else:
        T=int(q[1])
        if s==0:
            if T==2:
                S.append(q[2])
            else:
                S.appendleft(q[2])
        else:
            if T==1:
                S.append(q[2])
            else:
                S.appendleft(q[2])
if s==1:
    S.reverse()
S="".join(S)
print(S)
