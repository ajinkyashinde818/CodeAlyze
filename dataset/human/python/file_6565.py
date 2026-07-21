from collections import deque

S = input()
Q = int(input())
d = deque()
for s in S:
    d.append(s)
cnt = 0
for _ in range(Q):
    q = input().split()
    if q[0] == '1':
        cnt += 1
    else:
        if q[1] == '1':
            if cnt & 1:
                d.append(q[2])
            else:
                d.appendleft(q[2])
        else:
            if cnt & 1:
                d.appendleft(q[2])
            else:
                d.append(q[2])
if cnt & 1:
    ans = reversed(list(d))
else:
    ans = list(d)
print(''.join(ans))
