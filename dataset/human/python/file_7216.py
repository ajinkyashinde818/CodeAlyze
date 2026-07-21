from collections import deque

S = input()
Q = int(input())

d = deque(list(S))
reverse = False

for i in range(Q):
    query = input().split()

    if query[0] == '1':
        reverse = not reverse

    elif query[0] == '2':
        if query[1] == '1' and not reverse:
            d.appendleft(query[2])
        elif query[1] == '2' and not reverse:
            d.append(query[2])
        elif query[1] == '1' and reverse:
            d.append(query[2])
        elif query[1] == '2' and reverse:
            d.appendleft(query[2])

if reverse:
    d.reverse()

print(''.join(d))
