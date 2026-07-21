from collections import deque

S = input()
Q = int(input())

queue = deque(list(S))

r = False
for _ in range(Q):
    query = input()
    if query == '1':
        r ^= True
    else:
        _, f, c = query.split()
        front = f == '1'

        if r ^ front:
            queue.appendleft(c)
        else:
            queue.append(c)

if r:
    ans = ''.join(list(queue)[::-1])
else:
    ans = ''.join(queue)

print(ans)
