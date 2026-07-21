from collections import deque
s = deque(list(input()))
q = int(input())
cur = 0
for i in range(q):
    ls = list(map(str, input().split()))
    if len(ls) == 1:
        cur += 1
    else:
        if ls[1] == '1':
            if cur%2 == 0:
                s.appendleft(ls[2])
            else:
                s.append(ls[2])
        else:
            if cur%2 == 0:
                s.append(ls[2])
            else:
                s.appendleft(ls[2])
if cur%2 == 0:
    print(*s, sep='')
else:
    print(*list(s)[::-1], sep='')
