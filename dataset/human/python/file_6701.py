import collections
S = list(input())
s = collections.deque(S)
Q = int(input())
mode = 1
for _ in range(Q):
    tmp = tuple(input().split())
    if len(tmp) == 1:
        mode = 1 ^ mode
    else:
        t, f, c = tmp
        f = int(f)
        f -= 1
        if mode ^ f:
            s.appendleft(c)
        else:
            s.append(c)
if mode:
    print("".join(list(s)))
else:
    print("".join(list(s)[::-1]))
