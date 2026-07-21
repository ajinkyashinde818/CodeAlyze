s = input()
q = int(input())

from collections import deque

flip = False
deq = deque(s)

for _ in range(q):
    query = input().split(' ')
    if len(query)==1:
        flip = not flip
    else:
        f,c = int(query[1])-1,query[2]
        if flip ^ f:
            deq.append(c)
        else:
            deq.appendleft(c)

if flip:
    deq.reverse()

res =""
for c in deq:
    res+=c

print(res)
