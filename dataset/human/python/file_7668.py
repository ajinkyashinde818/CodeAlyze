from collections import deque
S = deque(input())
Q = int(input())
x = 1
l=[]
for i in range(Q):
    a, *b = input().split()
    if a == "1":
        x *= -1
    elif a == "2":
        c, d = b
        if (c == "2" and x == -1) or  (c == "1" and x == 1):
            S.appendleft(d)
        else:
            S.append(d)
if x == -1:
    S.reverse()
print(*S, sep="")
