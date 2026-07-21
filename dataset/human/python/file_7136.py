s = list(str(input()))
q = int(input())
flag = 1
from collections import deque
s = deque(s)
for i in range(q):
    query = list(map(str, input().split()))
    if len(query) == 1:
        flag = 1-flag
    else:
        t, f, c = query
        if f == '1':
            if flag:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if flag:
                s.append(c)
            else:
                s.appendleft(c)

s = list(s)
if not flag:
    s.reverse()
print(''.join(s))
