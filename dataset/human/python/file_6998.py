from collections import deque

S = input()

q = deque(S)
forward = True
for _ in range(int(input())):
    TFC = input().split()
    if TFC[0] == '1':
        forward = not forward
    else:
        if (TFC[1] == '1') == forward:
            q.appendleft(TFC[2])
        else:
            q.append(TFC[2])

if not forward:
    q.reverse()

print(''.join(q))
