from collections import deque
s = deque(input())
n = int(input())
now: bool = True

for i in range(n):
    q = list(input().split())
    if q[0] == '1':
        now = not now
    else:
        if (q[1] == '1' and now == True) or (q[1] == '2' and now == False):
            s.appendleft(q[2])
        elif (q[1] == '1' and now == False) or (q[1] == '2' and now == True):
            s.append(q[2])
if now == True:
    print(''.join(s))
else:
    print(''.join(reversed(s)))
