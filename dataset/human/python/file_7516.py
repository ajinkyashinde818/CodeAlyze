from collections import deque

S = deque(list(input()))

Q = int(input())

cnt = 0
for i in range(Q):
    l = list(map(str,input().split()))
    if int(l[0]) == 1:
        cnt += 1
    else:
        if int(l[1]) == 1:
            if cnt % 2 == 1:
                S.append(l[2])
            else:
                S.appendleft(l[2])
        else:
            if cnt % 2 == 1:
                S.appendleft(l[2])
            else:
                S.append(l[2])

if cnt % 2 == 1:
    S = list(S)[::-1]
print(''.join(S))
