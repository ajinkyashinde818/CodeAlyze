from collections import deque

S = input()
Q = int(input())

Query = [[0] * 3 for _ in range(Q)]
for i in range(Q):
    tmp = input().split()
    if tmp[0] == "1":
        Query[i][0] = 1
    elif tmp[0] == "2":
        Query[i][0] = 2
        Query[i][1] = int(tmp[1])
        Query[i][2] = tmp[2]

q = deque()
q.extend(S)
rev_flag = 0


for i in range(Q):
    if Query[i][0] == 1:
        rev_flag = (1 - rev_flag)
    else:
        if Query[i][1] == 1 and rev_flag == 0:
            q.appendleft(Query[i][2])
        elif Query[i][1] == 1 and rev_flag == 1:
            q.append(Query[i][2])
        elif Query[i][1] == 2 and rev_flag == 0:
            q.append(Query[i][2])
        elif Query[i][1] == 2 and rev_flag == 1:
            q.appendleft(Query[i][2])

if rev_flag == 1:
    q.reverse()
print("".join(list(q)))
