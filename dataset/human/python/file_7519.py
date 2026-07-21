from collections import deque

S = deque(input())
Q = int(input())
Query = [input().split() for i in range(Q)]
order = 1

for i in range(Q):
    if Query[i][0] == '1':
        order *= -1
    else:
        F = Query[i][1]
        C = Query[i][2]

        if F == '1':
            if order == 1:
                S.appendleft(C)
            else:
                S.append(C)
        else:
            if order == 1:
                S.append(C)
            else:
                S.appendleft(C)

S = ''.join(list(S))

print(S[::order])
