from collections import deque

S = str(input())
Q = int(input())
Query = [list(map(str, input().split())) for _ in range(Q)]

sArry = deque(S)
rFlag = False
for i in range(Q):
    if Query[i][0] == '1':
        rFlag = (rFlag == False)
        
    else:
        if rFlag:
            if Query[i][1] == '1':
                sArry.append(Query[i][2])
            else:
                sArry.appendleft(Query[i][2])
        else:
            if Query[i][1] == '1':
                sArry.appendleft(Query[i][2])
            else:
                sArry.append(Query[i][2])
            
#    print("  ", i, rFlag, "".join(sArry), Query[i])



if rFlag:
    print("".join(reversed(sArry)))
else:
    print("".join(sArry))
