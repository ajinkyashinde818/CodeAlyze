from collections import deque

S = list(input())
Q = int(input())

S = deque(S)

Query = [list(input()) for i in range(Q)]

rev_cnt = 0

for i in range(Q):
    if Query[i][0] == "1":
        rev_cnt += 1
    else:
        if Query[i][2] == "1":
            if rev_cnt % 2 == 1:
                S.append(Query[i][4])
            else:
                S.appendleft(Query[i][4])
        else:
            if rev_cnt % 2 == 1:
                S.appendleft(Query[i][4])
            else:
                S.append(Query[i][4])

if rev_cnt % 2 == 1:
    while len(S) != 0:
        print(S.pop(), end="")
else:
    while len(S) != 0:
        print(S.popleft(), end="")


print()
