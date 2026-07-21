from collections import deque
S = deque(list(input()))
Q = int(input())

flag = False
for _ in range(Q):
    q = list(input().split())
    if q[0] == '1':
        flag = True if flag is False else False
    else:
        if flag is False:
            if q[1] == '1':
                S.appendleft(q[2])
            else:
                S.append(q[2])
        else:
            if q[1] == '1':
                S.append(q[2])
            else:
                S.appendleft(q[2])

if flag is True:
    S.reverse()
print(''.join(S))
