from collections import deque

S = deque(list(input()))
Q = int(input())
count = 0
for q in range(Q):
    Query = input().split()
    if Query == ['1']:
        count += 1
    else:
        if count % 2 == 0:
            if Query[1] == "1":
                S.appendleft(Query[2])
            else:
                S.append(Query[2])
        else:
            if Query[1] == "1":
                S.append(Query[2])
            else:
                S.appendleft(Query[2])
if count % 2 == 1:
    print(''.join(list(S)[::-1]))
else:
    print(''.join(S))
