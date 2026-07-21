from collections import deque
S = input()
Q = int(input())
pre = deque()
suf = deque()
rev = False
for i in range(Q):
    q = input().split()
    if len(q) == 1:
        rev = not rev
    else:
        if (not rev and q[1] == '1') or (rev and q[1] == '2'):
            pre.appendleft(q[2])
        else:
            suf.append(q[2])
if rev:
    S = S[::-1]
    p = list(suf)[::-1]
    s = list(pre)[::-1]
else:
    p = list(pre)
    s = list(suf)
print(''.join(p) + S + ''.join(s))
