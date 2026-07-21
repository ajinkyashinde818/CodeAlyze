from collections import deque

S = input()
Q = int(input())
ans = deque()
ans.append(S)
turncnt = 0
for i in range(Q):
    query = input().split()
    if (query[0] == "1"):
        turncnt = turncnt + 1
    if (query[0] == "2"):
        if (query[1] == "1"):
            if (turncnt % 2 == 0):
                ans.appendleft(query[2])
            else:
                ans.append(query[2])
        if (query[1] == "2"):
            if (turncnt % 2 == 0):
                ans.append(query[2])
            else:
                ans.appendleft(query[2])

anstr = "".join(ans)
if (turncnt % 2 == 1):
    anstr = anstr[::-1]
print(anstr)
