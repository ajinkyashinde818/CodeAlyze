from collections import deque

import sys
input = sys.stdin.readline

S = input().strip()

is_front = True # 最初は左向き
queue = deque(S)

Q = int(input())
for _ in range(Q):
    query = input().strip().split()
    if len(query) == 1:
        is_front = not is_front
    else:
        ti, fi, ci = query
        fi = int(fi)
        if is_front:
            if fi == 1:
                queue.appendleft(ci)
            else:
                queue.append(ci)
        else:
            if fi == 1:
                queue.append(ci)
            else:
                queue.appendleft(ci)

ans = "".join(queue)
if not is_front:
    ans = ans[::-1]
print(ans)
