from collections import deque

s = deque(input())
q = int(input())

rev = False

for _ in range(q):
    ls = list(input().split())
    if ls[0] == '1':
        rev = not rev
    elif rev ^ (ls[1] == '1'):
        s.appendleft(ls[2])
    else:
        s.append(ls[2])

if rev:
    s.reverse()

print(''.join(s))
