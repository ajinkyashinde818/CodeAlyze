import sys
input = sys.stdin.readline

from collections import deque


S = deque(input().strip())
q = int(input())

cnt = 0
for _ in range(q):
    query = input().strip()
    if query == "1":
        cnt += 1
    else:
        t, f, c = query.split()
        if cnt % 2 == 0:
            if f == "1":
                S.appendleft(c)
            else:
                S.append(c)
        else:
            if f == "1":
                S.append(c)
            else:
                S.appendleft(c)
ans = "".join(S)

print(ans if cnt % 2 == 0 else ans[::-1])
