from collections import deque

S = input()
Q = int(input())

que = deque()

for s in S:
    que.append(s)

swi = 0
for _ in range(Q):
    query = input().split()

    if query[0] == "1":
        swi ^= 1
    else:
        if query[1] == "1":
            if swi == 0:
                que.appendleft(query[2])
            else:
                que.append(query[2])
        else:
            if swi == 0:
                que.append(query[2])
            else:
                que.appendleft(query[2])

if swi == 1:
    que.reverse()

print("".join(list(que)))
