from collections import deque
import sys
input = sys.stdin.readline
s = str(input().rstrip())
ans = deque(list(s))

f = True
q = int(input())
for i in range(q):
    q = list(map(str, input().split()))
    if int(q[0]) == 1:
        f = not f
    else:
        f_i = int(q[1])
        if (f_i == 1) ^ f:
            ans.append(q[2])
        else:
            ans.appendleft(q[2])
ans = "".join(list(ans))
if not f:
    ans = ans[::-1]
print(ans)
