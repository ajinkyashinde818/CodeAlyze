from collections import deque
d = deque(input())
q = int(input())
reverse = False
for _ in range(q):
    query = list(input().split())
    if query[0] == '1':
        if reverse:
            reverse = False
        else:
            reverse = True
        continue
    else:
        if query[1] == '1':
            if reverse:
                d.append(query[2])
            else:
                d.appendleft(query[2])
        else:
            if reverse:
                d.appendleft(query[2])
            else:
                d.append(query[2])

if reverse:
    d = list(reversed(d))

print(''.join(map(str, d)))
