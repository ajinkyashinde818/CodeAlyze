from collections import deque

s = list(input())
s = deque(s)
n = int(input())
dire = False

for i in range(n):
    q = input().split()
    if q[0] == '1':
        dire = not dire
    else:
        t = int(q[1])-1

        if dire ^ t:
            s.append(q[2])
        else:
            s.appendleft(q[2])
if dire:
    s.reverse()

print(''.join(s))
