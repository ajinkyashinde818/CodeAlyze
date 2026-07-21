s = input()
q = int(input())
from collections import deque
f_s = deque([])
b_s = deque([])
fwd = 1
for i in range(q):
    qs = list(input().split())
    if qs[0] == '1':
        fwd ^= 1
    elif qs[1] == '1':
        if fwd:
            f_s.appendleft(qs[2])
        else:
            b_s.append(qs[2])
    else:
        if fwd:
            b_s.append(qs[2])
        else:
            f_s.appendleft(qs[2])
print("".join(f_s)+s+"".join(b_s) if fwd else ("".join(f_s)+s+"".join(b_s))[::-1])
