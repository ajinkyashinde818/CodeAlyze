s = input()
q = int(input())
Q = [input().split() for _ in range(q)]

import collections
dq = collections.deque(s)

rev = 1
for i in Q:
    if i == ['1']:
        rev *= -1
    else:
        if (i[1] == '1' and rev == 1) or (i[1] == '2'and rev == -1):
            dq.appendleft(i[2])
        else:
            dq.append(i[2])

if rev == 1:
    print(''.join(dq))
else:
    print(''.join(dq)[::-1])
