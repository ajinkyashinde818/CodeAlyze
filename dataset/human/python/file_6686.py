from collections import deque
import copy
s = input()
q_ = int(input())
query = [input().split() for _ in range(q_)]
l = deque(s)
flag = 0

for q in query:
    if q[0] == '1':
        flag += 1
        continue
    elif q[0] == '2':
        if (int(q[1]) + flag) % 2 == 1:
            l.appendleft(q[2])
        else:
            l.append(q[2])

if flag % 2 == 1:
    l.reverse()

print(''.join(l))
