from collections import deque

S = list(input())
d = deque(S)
Q = int(input())
r_flag = 0

def top(d,C,r_flag):
    if r_flag:
        d.append(C)
    else:
        d.appendleft(C)

def bottom(d,C,r_flag):
    if r_flag:
        d.appendleft(C)
    else:
        d.append(C)

for i in range(Q):
    tmp = list(input().split())
    if tmp[0] == "1":
        if r_flag == 0:
            r_flag = 1
        else:
            r_flag = 0
    else:
        if tmp[1] == "1":
            top(d,tmp[2],r_flag)
        else:
            bottom(d,tmp[2],r_flag)

d = list(d)
if r_flag:
    d.reverse()
print("".join(d))
