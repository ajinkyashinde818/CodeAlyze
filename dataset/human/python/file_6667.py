from collections import deque
S = deque(list(input()))
Q = int(input())
flag = 1
for i in range(Q):
    a = list(input().split())
    if a[0] == '1':
        if flag == 0:
            flag = 1
        else:
            flag = 0
    else:
        if a[1] == '1':
            if flag == 1:
                S.appendleft(a[2])
            else:
                S.append(a[2])
        else:
            if flag == 1:
                S.append(a[2])
            else:
                S.appendleft(a[2])
if flag == 1:
    print(''.join(S))
else:
    S.reverse()
    print(''.join(S))
