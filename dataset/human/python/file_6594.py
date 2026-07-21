from collections import deque
s = deque(list(input()))
n = int(input())
flag = True
for _ in range(n):
    q = list(map(str, input().split()))
    if len(q) == 1:
        if flag:
            flag = False
        else:
            flag = True
    if len(q) == 3:
        if (q[1] == "1" and flag == False) or (q[1] == "2" and flag):
            s.append(q[2])
        else:
            s.appendleft(q[2])
if flag == False:
    s.reverse()
print("".join(s))
