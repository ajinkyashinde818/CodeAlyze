from collections import deque
s = input()
s = deque(list(s))
q = int(input())
inv=False
for _ in range(q):
    query = input()
    if query == '1':
        inv=not(inv)
    else:
        _q,f,c = query.split()
        if inv:
            if f=='2':
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if f=='1':
                s.appendleft(c)
            else:
                s.append(c)

if inv:
    print(''.join(list(s)[::-1]))
else:
    print(''.join(list(s)))
