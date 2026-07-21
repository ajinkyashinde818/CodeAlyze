S = input()
Q = int(input())
flag = True
from collections import deque
que=deque(S)

for i in range(Q):
    a = input().split()
    if a[0]=="1":
        flag = not flag

    else:
        f = a[1]
        c = a[2]
        if f=="1":
            if flag:
                que.appendleft(c)
            else:
                que.append(c)
        else:
            if flag:
                que.append(c)
            else:
                que.appendleft(c)

if not flag:
    que.reverse()

print("".join(que))
