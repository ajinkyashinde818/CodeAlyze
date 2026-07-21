from collections import deque

S = deque(input())
Q = int(input())
rev = 0

for i in range(Q):
    l = str(input())
    if l[0] == '1':
        rev = (rev + 1) % 2
    else:
        two, F, C = l.split()
        if rev == 0:
            if F == '1':
                S.appendleft(C)
            else:
                S.append(C)

        else:
            if F == '1':
                S.append(C)

            else:
                S.appendleft(C)

if rev == 0:
    print(''.join(S))
else:
    print(''.join(list(reversed(S))))
