from collections import deque

s = deque(list(input()))
n = int(input())
q = [list(input().split()) for _ in range(n)]
rev = False

for tfc in q:
    if tfc[0] == "1" and rev is False:
        rev = True
    elif tfc[0] == "1" and rev is True:
        rev = False
    elif rev is False:
        if tfc[1] == "1":
            s.appendleft(tfc[2])
        else:
            s.append(tfc[2])
    elif rev is True:
        if tfc[1] == "1":
            s.append(tfc[2])
        else:
            s.appendleft(tfc[2])

if rev:
    s.reverse()
print("".join(s))
