from collections import deque
 
S = input()
L = deque([])
for c in S:
    L.append(c)
Q = int(input())
flag = 1
for _ in range(Q):
    q = list(input().split())
    if q[0] == "1":
        flag *= -1
    else:
        F = q[1]
        if F == "1":
            if flag == 1:
                L.appendleft(q[2])
            else:
                L.append(q[2])
        else:
            if flag == 1:
                L.append(q[2])
            else:
                L.appendleft(q[2])
if flag == 1:
    print("".join(map(str, L)))
else:
    L.reverse()
    print("".join(map(str, L)))
