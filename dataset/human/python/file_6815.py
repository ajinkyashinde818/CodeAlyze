import collections
S = input()
dq = collections.deque(S)
Q = int(input())
q = []
hanten = False
for _ in range(Q):
    q = input().split(" ")
    if q[0] == '1':
        hanten = not hanten
    else:
        if q[1] == '1' and not hanten:
            dq.appendleft(q[2])
        elif q[1] == '1' and hanten:
            dq.append(q[2])
        elif q[1] == '2' and not hanten:
            dq.append(q[2])
        else:
            dq.appendleft(q[2])
if not hanten:
    print(''.join(dq))
else:
    print(''.join(dq)[::-1])
