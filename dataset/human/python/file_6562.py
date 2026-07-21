from collections import deque
s = deque(input())
Q = int(input())
a = True
for i in range(Q):
    t = list(input().split())
    if t[0] == "1":
        a = not(a)
    if t[0] == "2":
        if ((t[1] == "1") and not a ) or ((t[1]=="2") and a ):
            s.append(t[2])
        else:
            s.appendleft(t[2])
if not a :
    s.reverse()
print(*s,sep = "")
