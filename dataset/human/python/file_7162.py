from collections import deque
q = deque(input())
Q = int(input())
cnt = 0
for i in range(Q):
    query = input().split()
    if query[0] == '1':
        cnt += 1
    else :
        if query[1] == '1':
            if cnt % 2 == 0:
                q.appendleft(query[2])
            else :
                q.append(query[2])
        else :
            if cnt % 2 == 1:
                q.appendleft(query[2])
            else :
                q.append(query[2])
if cnt % 2 == 1: q.reverse()
print(''.join(q))
