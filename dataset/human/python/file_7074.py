from collections import deque

S = deque(input())
Q = int(input())

flag = False
for _ in range(Q):
    q = input()
    if q[0] == '1':
        flag = not flag
    else:
        _, f, c = q.split()
        if flag:
            if f == '2':
                S.appendleft(c)
            else:
                S.append(c)
        else:
            if f == '1':
                S.appendleft(c)
            else:
                S.append(c)

if flag:
    S.reverse()
print(''.join(S))
