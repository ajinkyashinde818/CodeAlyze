from collections import deque

S = input()
Q = int(input())
s = deque(S)
reverse = True

for i in range(Q):
    tmp = list(input().split())
    if tmp[0] == '1':
        reverse = not reverse
    if tmp[0] == '2':
        F = tmp[1]
        C = tmp[2]
        if F == '1':
            if reverse:
                s.appendleft(C)
            else:
                s.append(C)
        else:
            if reverse:
                s.append(C)
            else:
                s.appendleft(C)
if reverse:
    print(''.join(s))
else:
    print(''.join(list(s)[::-1]))
