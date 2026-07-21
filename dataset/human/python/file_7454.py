from collections import deque

S = input()
Q = int(input())
s = deque(list(S))
re = False
 
for i in range(Q):
    q = list(map(str,input().split()))
    if q[0] == "1":
        re = not re
    else:
        b = int(q[1])-1
        if (re and b) or not(re or b):
            s.appendleft(q[2])
        else:
            s.append(q[2])
 
ans = ""
if re:
    while s:
    	ans += s.pop()
else:
    while s:
        ans += s.popleft()
print(ans)
