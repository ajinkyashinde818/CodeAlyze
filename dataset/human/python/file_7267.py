from collections import deque

s = deque(input())
q = int(input())
flag = 0
for i in range(q):
    query = list(input().split())
    if query[0] == "1":
        flag = (flag+1)%2
    else:
        if flag == 0:
            if query[1] == "1":
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if query[1] == "2":
                s.appendleft(query[2])
            else:
                s.append(query[2])

s = list(s)
if flag == 0:
    for i in s:
        print(i, end="")
if flag == 1:
    l = len(s)
    for i in range(l):
        print(s[l-i-1], end="")

print()
