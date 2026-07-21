from _collections import deque
S = deque(input())
Q = int(input())
dir = 1

for i in range(Q):
    query = list(input().split())
    if len(query) == 1:
       dir *= -1
    else:
        T, f, c = query
        if int(f) == 1:
            if dir == 1:
                S.appendleft(c)
            else:
                S.append(c)
        else:
            if dir == 1:
                S.append(c)
            else:
                S.appendleft(c)
if dir == -1:
    S.reverse()
print(''.join(S))
