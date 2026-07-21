from collections import deque
s = deque(input())
q = int(input())

ok = True
for i in range(q):
    query = input()
    if query[0] == '1':
        if ok:
            ok = False
        else:
            ok = True
    else:
        query = query.split()
        if ok:
            if query[1] == '1':
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if query[1] == '1':
                s.append(query[2])
            else:
                s.appendleft(query[2])
if not ok:
    s.reverse()
print(''.join(list(s)))
