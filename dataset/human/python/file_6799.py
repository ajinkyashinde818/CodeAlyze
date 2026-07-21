from collections import deque
s = deque(input())
Q = int(input())
count = 0
for i in range(Q):
    q = input().split()
    if int(q[0]) == 1:
        count += 1
    else:
        f, c = int(q[1]), q[2]
        if (count%2==0 and f==1) or (count%2==1 and f==2):
            s.appendleft(c)
        else:
            s.append(c)
if count%2==1:
    s.reverse()
print("".join(s))
