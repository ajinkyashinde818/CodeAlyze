from collections import deque
s = deque(input())
q = int(input())
li = [list(map(str, input().split())) for _ in range(q)]

frag = True

for i in range(q):
    que = li[i]
    if que[0] == "1":
        if frag:
            frag = False
        else:
            frag = True
    else:
        f = que[1]
        c = que[2]
        if frag:
            if f == "1":
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if f == "1":
                s.append(c)
            else:
                s.appendleft(c)

if frag:
    print("".join(s))
else:
    s.reverse()
    print("".join(s))
