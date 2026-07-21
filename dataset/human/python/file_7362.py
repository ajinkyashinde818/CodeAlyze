from collections import deque

s = deque(input().rstrip())
q = int(input())

reverse = False
for i in range(q):
    query = input()
    if int(query[0]) == 1:
        reverse = not reverse
    else:
        _, f, c = query.split()
        if int(f) == 1:
            if reverse:
                s.append(c)
            else:
                s.appendleft(c)
        else:
            if reverse:
                s.appendleft(c)
            else:
                s.append(c)
if reverse:
    s.reverse()

print(''.join(s))
