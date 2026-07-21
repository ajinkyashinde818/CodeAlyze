from collections import deque
s = deque(input())
q_num = int(input())
d = 0
for _ in range(q_num):
    q = input().split()
    if q[0] == '1':
        d = 1 - d
    else:
        if d == 0 and q[1] == '1' or d == 1 and q[1] == '2':
            s.appendleft(q[2])
        else:
            s.append(q[2])

s = ''.join(s)
if d == 1:
    s = s[::-1]
print(s)
