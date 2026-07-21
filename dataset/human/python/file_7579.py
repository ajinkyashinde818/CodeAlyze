from collections import deque

S = input()
Q = int(input())
d = deque()
for i in S:
    d.append(i)
flag = True
for _ in range(Q):
    q = [i for i in input().split()]
    if int(q[0]) == 1:
        flag = not flag
    else:
        if (int(q[1]) == 1 and flag) or (int(q[1]) == 2 and not flag):
            d.appendleft(q[2])
        else:
            d.append(q[2])
S = ""
while(len(d)>0):
    if flag:
        S += d.popleft()
    else:
        S += d.pop()
print(S)
