from collections import deque
s = deque(input())
num = int(input())
cnt = 0
for _ in range(num):
    t = input().split()
    if t[0] == "1":
        cnt += 1
    else:
        if (int(t[1])+cnt) % 2 == 1:
            s.appendleft(t[2])
        else:
            s.append(t[2])
if cnt % 2 == 1:
    s.reverse()
print("".join(s))
