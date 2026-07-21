from collections import deque

s = input()
q = int(input())

deq = deque(s)
pol = 0
for _ in range(q):
    query = input()
    if query[0] == '1':
        pol ^= 1
        continue
    _, f, c = query.split()
    op = int(f) - 1
    if op ^ pol:
        deq.append(c)
    else:
        deq.appendleft(c)

if pol:
    print(''.join(reversed(deq)))
else:
    print(''.join(deq))
