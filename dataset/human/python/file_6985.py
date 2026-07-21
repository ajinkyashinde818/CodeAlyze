from collections import deque
s = list(input())
q = int(input())
d = deque(s)
rot = 0
for i in range(q):
    que = list(map(str,input().split()))
    if len(que) == 1:
        rot += 1
    else:
        num = int(que[1])
        cha = que[2]
        if num == 1 and rot % 2 == 0:
            d.appendleft(cha)
        elif num == 1 and rot % 2 == 1:
            d.append(cha)
        elif num == 2 and rot % 2 == 0:
            d.append(cha)
        elif num == 2 and rot % 2 == 1:
            d.appendleft(cha)
d = list(d)
if rot % 2 == 1:
    d.reverse()
    print("".join(d))
else:
    print("".join(d))
