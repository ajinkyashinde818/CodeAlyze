from sys import stdin
from collections import deque
S = (stdin.readline().rstrip())
Q = int(stdin.readline().rstrip())
cnt = 0
ccnt = 0
s = deque(["@"])
for i in range(Q):
    data = [(x) for x in stdin.readline().rstrip().split()]
    if data[0] == "2":
        if data[1] == "1":
            if cnt % 2 == 0:
                s.appendleft(data[2])
            else:
                s.append(data[2])
        else:
            if cnt % 2 == 0:
                s.append(data[2])
            else:
                s.appendleft(data[2])
    else:
        cnt += 1
s = "".join(s)
if cnt % 2 != 0:
    s = s[::-1]
if cnt % 2 != 0:
    S = S[::-1]
ans = s.replace("@",S)
print(ans)
