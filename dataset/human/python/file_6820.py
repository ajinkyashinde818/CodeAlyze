from collections import deque
s = deque(input())
n = int(input())
initial = True
for i in range(n):
    order = list(input().split())
    if len(order) == 3:
        if initial:
            if int(order[1]) == 1:
                s.appendleft(order[2])
            else:
                s.append(order[2])
        else:
            if int(order[1]) == 1:
                s.append(order[2])
            else:
                s.appendleft(order[2])
    else:
        initial = not initial
    
if initial:
    print(''.join(s))
else:
    print(''.join(s)[::-1])
