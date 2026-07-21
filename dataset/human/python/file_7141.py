from collections import deque
s = input()
q = int(input())
tmp = deque()
for i in range(len(s)):
    tmp.append(s[i])
flag = 0
for _ in range(q):
    _s = input()
    if _s == "1":
        flag += 1
    else:
        t, f, c = _s.split(" ")
        r = flag % 2
        if f == "1" and r == 0:
            #tmp = c + tmp
            tmp.appendleft(c)
        elif f == "1" and r == 1:
            #tmp = tmp + c
            tmp.append(c)
        elif f == "2" and r == 0:
            #tmp = tmp + c
            tmp.append(c)
        elif f == "2" and r == 1:
            #tmp = c + tmp
            tmp.appendleft(c)
if flag % 2 == 0:
    for i in range(len(tmp)):
        print(tmp.popleft(), end="")
else:
    for i in range(len(tmp)):
        print(tmp.pop(), end="")
