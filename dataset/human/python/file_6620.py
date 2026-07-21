S = input()

Q = int(input())

from collections import deque
ans = deque()

for s in S:
    ans.append(s)

rev = False
for _ in range(Q):
    q = input().split()
    if q[0] == "1":
        rev = not rev
    else:
        is_right = (q[1] =="2") ^ rev
        if is_right:
            for s in q[2]:
                ans.append(s)
        else:
            for s in q[2]:
                ans.appendleft(s)
if rev:
    ans.reverse()
print("".join(ans))
