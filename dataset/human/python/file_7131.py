from collections import deque

S = deque(input())
Q = int(input())
Qs = [list(input().split()) for i in range(Q)]

is_reverse = False
for query in Qs:
    if query[0] == '1' and len(S) != 1:
        is_reverse = not is_reverse
    else:
        f = int(query[1])
        c = query[2]
        if (f == 1 and is_reverse) or (f == 2 and not is_reverse):
            S.append(c)
        else:
            S.appendleft(c)

if is_reverse:
    S.reverse()

print(''.join(S))
