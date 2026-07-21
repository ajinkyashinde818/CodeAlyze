import sys
from collections import deque

s = deque([sys.stdin.readline().rstrip()])
q = int(input())
cnt = 0
for i in range(q):
    query = sys.stdin.readline().split()
    if query[0] == '1':
        cnt = (cnt + 1)%2
    else:
        if (int(query[1]) + cnt)%2 == 1:
            s.appendleft(query[2])
        else:
            s.append(query[2])
s = "".join(s)
if cnt:
    s = s[::-1]
print(s)
