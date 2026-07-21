from collections import deque
s = deque(list(input()))
n = int(input())
q = deque()
for _ in range(n):
    q.append(list(input().split()))
d = 0
for r in q:
    if r[0] == '1':
        d = d ^ 1
    else:
        if int(r[1]) & (d+1):
            s.appendleft(r[2])
        else:
            s.append(r[2])
if d == 1:
    s.reverse()
ans = "".join(list(s))
print(ans)
