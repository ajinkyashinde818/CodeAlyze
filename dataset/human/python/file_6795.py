from collections import deque
S = deque([input()])
Q = int(input())
Query = list(input().split() for i in range(Q))
sentou = 0
for i in range(Q):
    if Query[i][0] == "1":
        sentou += 1
    if Query[i][0] == "2":
        if Query[i][1] == "1":
            if sentou % 2:
                S.append(Query[i][2])
            else:
                S.appendleft(Query[i][2])
        if Query[i][1] == "2":
            if sentou % 2:
                S.appendleft(Query[i][2])
            else:
                S.append(Query[i][2])
ans = ""
for i in S:
    ans += i
if sentou % 2:
    print(ans[::-1])
else:
    print(ans)
