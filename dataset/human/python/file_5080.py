from collections import deque
n, m = map(int, input().split())
p = [tuple(map(int, input().split())) for _ in range(m)]

d = dict()
for a, b in p:
    if a not in d.keys():
        d[a] = [b]
    else:
        d[a].append(b)
    if b not in d.keys():
        d[b] = []

node = deque()
node.append((1, 0))
visit = set()
while node:
    (s, count) = node.popleft()
    if s in visit:
        continue
    if s == n:
        if count == 2:
            print('POSSIBLE')
            exit()
        else:
            break
    for i in d[s]:
        node.append((i, count+1))
    visit.add(s)
print('IMPOSSIBLE')
