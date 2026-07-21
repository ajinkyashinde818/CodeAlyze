from collections import deque
S = deque(input())
Q = int(input())
q = [input().split() for _ in range(Q)]
flag = True
for x in q:
    if x[0] == "1":
        if flag: flag = False
        else: flag = True
    else:
        if x[1] == "1":
            if flag: S.appendleft(x[2])
            else: S.append(x[2])
        else:
            if flag: S.append(x[2])
            else: S.appendleft(x[2])
s = list(S)
if not flag: s = s[::-1]
print("".join(s))
