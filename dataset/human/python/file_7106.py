from collections import deque
S = list(input()) 
d = deque()
for s in S:
    d.append(s)
q = int(input())
o = 0

for _ in range(q):
    qu = list(input().split())
    if len(qu) == 1:
        o = -1 if o == 0 else 0
    if len(qu) == 3:
        if qu[1] == '1':
            d.appendleft(qu[2]) if o == 0 else d.append(qu[2])
        if qu[1] == '2':
            d.append(qu[2]) if o == 0 else d.appendleft(qu[2])

r = ''
if o == 0:
    for _ in range(len(d)):
        r += d.popleft()
else:
    for _ in range(len(d)):
        r += d.pop()

print(r)
