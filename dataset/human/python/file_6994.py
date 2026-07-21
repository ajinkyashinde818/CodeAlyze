from collections import deque
S = deque(input())
Q = int(input())
count = 0
for i in range(Q):
    l = list(input().split())
    if len(l) == 1:
        count +=1
    else:
        l[1] = int(l[1])
        if count%2 == 1:
            if l[1] == 1:
                l[1] = 2
            else:
                l[1] = 1
        if l[1] == 1:
            S.appendleft(l[2])
        else:
            S.append(l[2])

if count%2 == 0:
    print(''.join(list(S)))
else:
    S.reverse()
    print(''.join(list(S)))
