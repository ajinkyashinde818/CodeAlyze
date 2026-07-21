from collections import deque

S = deque(list(str(input())))
Q = int(input())
flag = False

for i in range(Q):
    Query =  [str(p) for p in input().split()]
    if(int(Query[0]) == 1):
        flag = not(flag)
    else:
        if(int(Query[1]) == 1):
            if(flag):
                S.append(Query[2])
            else:
                S.appendleft(Query[2])
        else:
            if(flag):
                S.appendleft(Query[2])
            else:
                S.append(Query[2])

if(flag):
    S.reverse()

print("".join(list(S)))
