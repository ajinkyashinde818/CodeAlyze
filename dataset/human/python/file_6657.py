from collections import deque

S = input().rstrip()
Q = int(input())


rev = False
out = deque(S)
for i in range(Q):
    args = input().split()
    if args[0] == '1':
        rev = not rev
    else:
        t, f, c = args
        assert t == '2'
        if f == '1':
            if rev:
                out.append(c)
            else:
                out.appendleft(c)
        else:
            assert f == '2'
            if rev:
                out.appendleft(c)
            else:
                out.append(c)

if rev:
    out = reversed(out)
print(''.join(out))
