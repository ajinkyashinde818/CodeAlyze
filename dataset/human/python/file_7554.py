from collections import deque

S = input()
d = deque(S)
Q = int(input())
is_order = True
for i in range(Q):
    tmp = input()
    if len(tmp) == 1:
        t = 1
        is_order = not is_order
    else:
        t,f,c = tmp.split()
        f = int(f)
        if f == 1:
            if is_order:
                d.appendleft(c)
            else:
                d.append(c[::-1]) 
        else:
            if is_order:
                d.append(c)
            else:
                d.appendleft(c[::-1])
if is_order:
    print("".join(d))
else:
    print("".join(reversed(d)))
