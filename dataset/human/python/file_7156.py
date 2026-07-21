from collections import deque
S = deque(list(input()))
Q = int(input())
Flag = True
for _ in range(Q):
    q = input().split()
    if len(q) == 1:
        Flag = False if Flag else True
    else:
        if Flag:
            if q[1] == '1':
                S.appendleft(q[2])
            else:
                S.append(q[2])
        else:
            if q[1] == '1':
                S.append(q[2])
            else:
                S.appendleft(q[2])
if Flag:
    print(''.join(S))
else:
    print(''.join(reversed(S)))
