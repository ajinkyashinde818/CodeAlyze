from collections import deque
s = input()
q = int(input())
f = ""
b = ""
forward = True
for _ in range(q):
    que = list(input().split())
    if int(que[0]) == 1:
        if forward:
            forward = False
        else:
            forward = True
    else:
        if (int(que[1]) == 1 and forward) or (int(que[1]) == 2 and not forward):
            f+=que[2]
        else:
            b+=que[2]

if forward:
    print(f[::-1]+s+b)
else:

    print(b[::-1]+s[::-1]+f)
