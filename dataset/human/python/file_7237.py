from collections import deque


s = list(input())
q = int(input())
query = [list(input().split()) for i in range(q)]

deq = deque(s)

flag = 1
for i in range(q):
    if query[i][0] == "1":
        flag ^= 1
    else:
        _, f, c = query[i]
        f = int(f) % 2
        if flag ^ f:
            deq.append(c)
        else:
            deq.appendleft(c)

ans = "".join(deq)
if flag:
    print(ans)
else:
    print(ans[::-1])
