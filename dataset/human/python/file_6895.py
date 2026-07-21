from collections import deque
s = list(input())
q = int(input())
d = deque()
d.append(0)
now = 1
for i in range(q):
    q1 = list(input())
    if len(q1) == 1:
        now *= -1
    else:
        if q1[2] == "1":
            if now == 1:
                d.appendleft(q1[4])
            else:
                d.append(q1[4])
        else:
            if now == 1:
                d.append(q1[4])
            else:
                d.appendleft(q1[4])
ans = ""
#print(now,d)
while len(d):
    if now == 1:
        a = d.popleft()
    else:
        a = d.pop()
    if a == 0:
        if now == 1:
            for i in range(len(s)):
                ans += s[i]
        else:
            for i in range(len(s)):
                ans += s[-(i+1)]
    else:
        ans += a
print(ans)
