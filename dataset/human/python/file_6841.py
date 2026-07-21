from collections import deque
s = input()
q = int(input())
hanten = 0
ans = deque(s)
for _ in range(q):
    a = list(input().split())
    if a[0] == "1":
        hanten += 1
    else:
        if hanten % 2 == 0:
            if a[1] == "1":
                ans.appendleft(a[2])
            if a[1] == "2":
                ans.append(a[2])
        else:
            if a[1] == "1":
                ans.append(a[2])
            if a[1] == "2":
                ans.appendleft(a[2])
if hanten % 2 == 0:
    print(*ans, sep="")
else:
    ans.reverse()
    print(*ans, sep="")
