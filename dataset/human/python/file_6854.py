from collections import deque
S = deque(list(input()))
Q = int(input())
cnt = 0
for i in range(Q):
    query = list(input().split())
    if query[0] == '1':
        cnt += 1
    elif query[1] == '1':
        if cnt % 2 == 0:
            S.appendleft(query[2])
        else:
            S.append(query[2])
    else:
        if cnt % 2 == 0:
            S.append(query[2])
        else:
            S.appendleft(query[2])
if cnt % 2 != 0:
    S.reverse()
print(''.join(S))
