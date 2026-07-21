import sys
from collections import deque

s = deque(map(str, input().rstrip()))

cnt = 0
while s:
    if s[0] != s[-1]:
        if s[0] != "x" and s[-1] != "x":
            print(-1)
            sys.exit()
        elif s[0] == "x":
            tmp = s.popleft()
        else:
            tmp = s.pop()
        cnt += 1
    elif len(s) <= 1:
        break
    else:
        s.popleft()
        s.pop()

print(cnt)
