from collections import deque
d = deque()
for x in input():
    d.append(x)
Q = int(input())
f = 0
for _ in range(Q):
    l = list(input().split())
    if l[0] == '1':
        f ^= 1
    else:
        if f == 0: 
            if l[1] == '2': d.append(l[2])
            else: d.appendleft(l[2])
        else:
            if l[1] == '2': d.appendleft(l[2])
            else: d.append(l[2])
if f:
    d.reverse()
print("".join(d))
