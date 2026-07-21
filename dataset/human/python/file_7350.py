from collections import deque

s = deque(list(input()))
q = int(input())
rev = False
for _ in range(q):
    qr = list(map(str, input().split()))
    if qr[0] == '1':
        rev = 1 - rev
    else:
        if qr[1] == '1':
            if rev: s.append(qr[2])
            else  : s.appendleft(qr[2])
        else:
            if rev: s.appendleft(qr[2])
            else  : s.append(qr[2])
if rev:
    s.reverse()
    print(''.join(s))
else:
    print(''.join(s))
