from collections import deque
S = list(input())
s = deque(S)
Q = int(input())
t = 0
for i in range(Q):
    qi = input()
    if qi == "1":
        t += 1
    else:
        qi = list(qi)
        if (int(qi[2])+t) % 2 ==0:
            s.append(qi[4])
        else:
            s.appendleft(qi[4])

s = list(s)
if t % 2 == 1:
    ans = [[] for j in range(len(s))]
    for i in range(len(s)):
        ans[i] = s[len(s)-i-1]
else:
    ans = s

print("".join(ans))
