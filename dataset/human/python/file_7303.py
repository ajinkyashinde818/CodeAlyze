from collections import deque
S = deque(list(input()))
Q = int(input())
t = 0
for i in range(Q):
    query = input().split()
    if int(query[0]) == 1:
        t += 1
    else:
        query[1] = int(query[1])
        if t % 2 == 1:
            if query[1] == 1:
                query[1] = 2
            else:
                query[1] = 1
        if query[1] == 1:
            S.appendleft(query[2])
        else:
            S.append(query[2])
if t % 2 == 1:
    S.reverse()
print("".join(S))
