from collections import deque
s = deque(input())
n = int(input())
qs = [list(input().split()) for i in range(n)]
pre = deque()
suf = deque()
frag = True
for q in qs:
    if len(q) == 1:
        frag = not frag
    else:
        if (frag, q[1]) == (True, "1") or (frag, q[1]) == (False, "2"):
            pre.appendleft(q[2])
        else:
            suf.append(q[2])
if frag is True:
    print("".join(list(pre)+list(s)+list(suf)))
else:
    suf.reverse()
    s.reverse()
    pre.reverse()
    print("".join(list(suf)+list(s)+list(pre)))
