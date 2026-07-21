from collections import deque

S=input()
Q=int(input())
Query=[[j for j in input().split()] for i in range(Q)]

c=0
S0=deque(S)

for i in range(Q):
    if Query[i][0]=='1':
        c=c+1
    else:
        if ((Query[i][1]=='1')and(c%2==0)) or ((Query[i][1]=='2')and(c%2==1)):
            S0.appendleft(Query[i][2])
        else:
            S0.append(Query[i][2])

if c%2==0:
    print(''.join(S0))
else:
    print(''.join(reversed(S0)))
