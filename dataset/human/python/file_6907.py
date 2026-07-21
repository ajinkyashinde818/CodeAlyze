from collections import deque #deque
s = input()
q = int(input())
flag = 1
d = deque(s)
for i in range(q):
    in_line = input().split()
    if in_line[0] == "1":
        flag *= -1
    else:
        if in_line[1] == "1":
            if flag == 1:
                d.appendleft(in_line[2])
            else:
                d.append(in_line[2])
        else:
            if flag == 1:
                d.append(in_line[2])
            else:
                d.appendleft(in_line[2])
if flag == -1:
    d.reverse()
print("".join(d))
