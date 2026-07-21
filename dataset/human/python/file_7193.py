from collections import deque

s = input()

q = int(input())

d = deque(list(s))

inversed = -1

for i in range(q):
    query = list(input().split())
    if int(query[0]) == 1:
        inversed *= -1
    else:
        if int(query[1]) == 1:
            if inversed < 0:
                d.appendleft(query[2])
            else:
                d.append(query[2])
        else:
            if inversed < 0:
                d.append(query[2])
            else:
                d.appendleft(query[2])

if inversed < 0:
    print(''.join(list(d)))
else:
    print(''.join(list(d)[::-1]))
