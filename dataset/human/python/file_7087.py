from collections import deque
s = input()
q = int(input())

s = deque(s)
flip = False

for i in range(q):
    Q = list(input().split())
    if int(Q[0]) == 1:
        flip = not flip
    else:
        if int(Q[1]) == 1:
            if not flip:
                s.appendleft(Q[2])
            else:
                s.append(Q[2])
        else:
            if not flip:
                s.append(Q[2])
            else:
                s.appendleft(Q[2])

ans = ''

for _ in range(len(s)):
    if not flip:
        ans += s.popleft()
    else:
        ans += s.pop()

print(ans)
