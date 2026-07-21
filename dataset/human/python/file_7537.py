from collections import deque

S = deque(input())
Q = int(input())

flag = 1
for i in range(Q):
    qry = input().split()

    if qry[0] == '1':
        if flag:
            flag = 0
        else:
            flag = 1
    
    elif qry[0] == '2':
        if flag:
            if qry[1] == '1':
                S.appendleft(qry[2])
            else:
                S.append(qry[2])
        else:
            if qry[1] == '1':
                S.append(qry[2])
            else:
                S.appendleft(qry[2])

S = ''.join(S)

if flag:
    print(S)
else:
    print(S[::-1])
