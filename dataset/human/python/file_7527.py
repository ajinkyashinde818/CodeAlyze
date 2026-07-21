from collections import deque

S = list(input())
s = deque(S)
q = int(input())
Q = [list(input().split()) for _ in range(q)]

rev = 0
for i in range(q):
    if len(Q[i]) == 1:
        rev += 1
        rev %= 2
    else:
        if rev == 0:
            if Q[i][1] == "1":
                s.appendleft(Q[i][2])
            else:
                s.append(Q[i][2])
        else:
            if Q[i][1] == "2":
                s.appendleft(Q[i][2])
            else:
                s.append(Q[i][2])

s = list(s)
if rev == 0:
    for i in range(len(s)):
        print(s[i],end="")
else:
    for i in reversed(range(len(s))):
        print(s[i],end="")
print()
