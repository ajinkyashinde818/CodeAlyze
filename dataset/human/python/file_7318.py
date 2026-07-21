from collections import defaultdict, Counter, namedtuple, deque
from bisect import bisect_left
from functools import reduce
import math

NN = 2020202
MOD = 10**9+7
INF = float("inf")


S = list(input().split())
Q = int(input())
query = [list(input().split()) for i in range(Q)]
que = deque(S)
rev = 0

for q in query:
    if len(q) == 1:
        rev ^= 1
    else:
        if q[1] == "1":
            if rev:
                que.append(q[2])
            else:
                que.appendleft(q[2])
        else:
            if rev:
                que.appendleft(q[2])
            else:
                que.append(q[2])
    # print(que)

if rev:
    print("".join(que)[::-1])
else:
    print("".join(que))
