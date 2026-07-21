from collections import deque

S = deque(input())
Q = int(input())
reverse_index = -1

for i in range(Q):
    query = input()
    if query[0] == '1':
        reverse_index *= -1
    elif query[0] == '2':
        if query[2] == '1':
            if reverse_index == -1:
                S.appendleft(query[4])
            else:
                S.append(query[4])
        else:
            if reverse_index == -1:
                S.append(query[4])
            else:
                S.appendleft(query[4])

if reverse_index == 1:
    S.reverse()
    print(*S, sep='')
else:
    print(*S, sep='')
