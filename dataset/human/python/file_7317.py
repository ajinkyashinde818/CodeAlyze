from collections import deque

S = [l for l in input()]
Q = int(input())
d = deque(S)
direction = 'f'

for i in range(Q):
    query = input()
    if query[0] == '1':
        if direction == 'f':
            direction = 'r'
        else :
            direction = 'f'
    else :
        t, f, c = query.split()
        if f == '1':
            if direction == 'f':
                d.appendleft(c)
            else :
                d.append(c)
        else :
            if direction == 'f':
                d.append(c)
            else :
                d.appendleft(c)

if direction == 'r':
    d.reverse()

print(''.join(d))
