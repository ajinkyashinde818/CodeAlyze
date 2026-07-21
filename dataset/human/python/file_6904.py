import sys
input = sys.stdin.readline
from collections import deque

S = deque(list(input().rstrip()))
Q = int(input())
Query = []

flag = 0

for _ in range(Q):
    Query.append(input().rstrip().split())

for i in Query:
    if i[0] == "1":
        flag += 1
    elif i[1] == "1":
        if flag % 2 == 0:
            S.appendleft(i[2])
        else:
            S.append(i[2])
    else:
        if flag % 2 == 0:
            S.append(i[2])
        else:
            S.appendleft(i[2])
if flag % 2 == 0:
    print("".join(list(S)))
else:
    print("".join(list(S))[::-1])
