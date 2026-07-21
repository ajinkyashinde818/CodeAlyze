S = list(input())
Q = int(input())

from collections import deque

S = deque(S)

tfc = [[] for _ in range(Q)]

swich = 0
for i in range(Q):
    tfc[i] = input().split()
    
    if int(tfc[i][0])==1:
        swich += 1
    else:
        if swich%2==0:
            if int(tfc[i][1])==1:
                S.appendleft(tfc[i][2])
            else:
                S.append(tfc[i][2])
        else:
            if int(tfc[i][1])==1:
                S.append(tfc[i][2])
            else:
                S.appendleft(tfc[i][2])

if swich%2==1:
    S = reversed(S)
    print("".join(S))
else:
    print("".join(S))
