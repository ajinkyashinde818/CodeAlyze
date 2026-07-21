from collections import deque

S = deque(input())
Q = int(input())

inv_flag = False
for _ in range(Q):
    query = list(input().split())
    if int(query[0]) == 1:
        inv_flag = not inv_flag
    else:
        if (int(query[1]) - 1) ^ inv_flag:
            S.append(query[2])
        else:
            S.appendleft(query[2])
if inv_flag:
    print(''.join(reversed(S)))
else:
    print(''.join(S))
