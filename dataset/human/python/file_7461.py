from collections import deque

S = deque(input())
Q = int(input())
Flag = False

for _ in range(Q):
    Query = input().split()
    if Query[0] == '1':
        if Flag == False:
            Flag = True
        else:Flag = False
    else:
        if Query[1] == '1':
            if Flag == False:S.appendleft(Query[2])
            else:S.append(Query[2])
        else:
            if Flag == False:S.append(Query[2])
            else:S.appendleft(Query[2])
l = list(S)
if Flag:print(''.join(l[::-1]))
else:print(''.join(l))
