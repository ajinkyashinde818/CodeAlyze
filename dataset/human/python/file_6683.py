from collections import deque
S = deque(list(input()))
Q = int(input())
rev_cnt = 0
for i in range(Q):
    query = [_ for _ in input().split()]
    if len(query) == 1:
        rev_cnt += 1
    else:
        if query[1] == '1':
            if rev_cnt%2 == 0:
                S.appendleft(query[2])
            else:
                S.append(query[2])
        else:
            if rev_cnt%2 == 0:
                S.append(query[2])
            else:
                S.appendleft(query[2])
if rev_cnt % 2 == 0:
    print(''.join(S))
else:
    S.reverse()
    print(''.join(S))
