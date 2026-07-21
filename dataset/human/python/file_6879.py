from collections import deque
s = deque(input())
q = int(input())
rev= 0
for i in range(q):
    x = list(input().split())
    if x [0] == '1':
        rev += 1
    else:
        if x[1] == '1':
            if rev % 2 == 0:
                s.appendleft(x[2])
            else:
                s.append(x[2])
        else:
            if rev % 2 == 0:
                s.append(x[2])
            else:
                s.appendleft(x[2])
if rev % 2 == 1:
    s.reverse()
print("".join(s))
