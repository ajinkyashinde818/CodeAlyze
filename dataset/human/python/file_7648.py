from collections import deque

S = deque(input())
Q = int(input())
rev = False
for _ in range(Q):
    s = input().split()
    if len(s) == 1:
        rev = not rev
        continue
    if not rev:
        if s[1] == '1':
            S.appendleft(s[2])
        else:
            S.append(s[2])
    else:
        if s[1] == '1':
            S.append(s[2])
        else:
            S.appendleft(s[2])
if rev:
    print(''.join(reversed(S)))
else:
    print(''.join(S))
