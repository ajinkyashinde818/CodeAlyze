from collections import deque


L = list(input().strip())
que = deque(L)
Q = int(input())
flip = False
for i in range(Q):
    q = list(map(str, input().split()))
    if len(q) == 1:
        flip = not flip
    else:
        t, f, c = q
        if flip is False and f == '1':
            que.appendleft(c)
        if flip is False and f == '2':
            que.append(c)
        if flip is True and f == '1':
            que.append(c)
        if flip is True and f == '2':
            que.appendleft(c)

if flip:
    que.reverse()

print(''.join(que))
