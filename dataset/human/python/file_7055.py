S = input()
Q = int(input())

from collections import deque
q = deque(S)
rev = False
for _ in range(Q):
    qr = input()
    if qr == '1':
        rev = not rev
        continue
    _,f,c = qr.split()
    if (f=='2') ^ rev:
        q.append(c)
    else:
        q.appendleft(c)

if rev:
    print(''.join(reversed(list(q))))
else:
    print(''.join(q))
