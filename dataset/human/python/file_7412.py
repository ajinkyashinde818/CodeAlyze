from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()
d = deque(input())

reverse = -1
n = int(input())
for i in range(n):
    query = input().split()
    if len(query) == 1:
        reverse *= (-1)
    else:
        f = int(query[1])
        c = query[2]
        if reverse == -1:
            if f == 1:
                d.appendleft(c)
            else:
                d.append(c)
        else:
            if f == 1:
                d.append(c)
            else:
                d.appendleft(c)

if reverse == 1:
    d.reverse()
# print(d)
print("".join(d))
