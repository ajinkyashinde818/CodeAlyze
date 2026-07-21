from collections import deque
S = deque(list(input()))
Q = int(input())

count = 0
for i in range(Q):
    a = list(map(str, input().split()))
    if a[0] == '1':
        count += 1
    elif a[0] == '2':
        if count % 2 == 0 and a[1] == '1':
            S.appendleft(a[2])
        elif a[1] == '1':
            S.append(a[2])
        elif count % 2 == 0:
            S.append(a[2])
        else:
            S.appendleft(a[2])


if count % 2 == 0:
    print(''.join(S))
else:
    S.reverse()
    print(''.join(S))
