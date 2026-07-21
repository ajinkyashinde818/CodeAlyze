from collections import deque
S = input()
que = deque()
que.append(S)
Q = int(input())
Front_flag = 1

for i in range(Q):
    Query = tuple(input().split())
    if len(Query) == 1:
        Front_flag = 1 - Front_flag
    else:
        a, b, c = Query
        if (Front_flag + int(b)) % 2 == 1:
            que.append(c)
        else:
            que.appendleft(c)

ans = ''.join(que)
if Front_flag:
    print(ans)
else:
    print(ans[::-1])
