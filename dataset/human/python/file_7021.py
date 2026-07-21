from collections import deque

S=deque(input())
flag=0
Q=int(input())

for queries in range(Q):
    q=list(input().split())

    if q[0]=="1":
        flag=1-flag
    else:
        x,y=q[1],q[2]

        if (flag+int(x))%2==0:
            S.append(y)
        else:
            S.appendleft(y)

if flag==0:
    print("".join(S))
else:
    print("".join(list(S)[::-1]))
