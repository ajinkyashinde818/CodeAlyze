from collections import deque

S = input()
Q = int(input())

Sq = deque(S)


flg = True
for i in range(Q):
    que = input()
    if que == "1":
        if flg:
            flg = False
        else:
            flg = True
    else:
        j, F, C = que.split()
        if int(F) == 1:
            if flg:
                Sq.appendleft(C)
            else:
                Sq.append(C)
        else:
            if flg:
                Sq.append(C)
            else:
                Sq.appendleft(C)

if flg:
    for i in Sq:
        print(i, end="")
else:
    Sq.reverse()
    for i in Sq:
        print(i, end="")
