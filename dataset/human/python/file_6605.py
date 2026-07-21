from collections import deque
s = deque(input())
q = int(input())
k = 0

for _ in range(q):
    Q = list(map(str,input().split()))
    if int(Q[0]) == 1:
        if k == 0:
            k = 1
        else:
            k = 0
    else:
        if k == 0:
            if int(Q[1]) == 1:
                s.appendleft(Q[2])
            else:
                s.append(Q[2])
        else:
            if int(Q[1]) == 1:
                s.append(Q[2])
            else:
                s.appendleft(Q[2])


if k == 1:
    s = list(s)[::-1]
    
print("".join(s))
