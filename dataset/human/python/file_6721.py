from collections import deque

S = deque(input())
Q = int(input())
Query = [input().split() for _ in range(Q)]

reverse = False
for query in Query:
    if query[0] == '1':
        reverse = not reverse
    else:
        if query[1] == ('2' if reverse else '1'):
            S.appendleft(query[2])
        else:
            S.append(query[2])
print(''.join(reversed(S) if reverse else S))
