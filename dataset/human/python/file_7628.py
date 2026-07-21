from collections import deque

ans = deque(input())
Q = int(input())
state = True
for _ in range(Q):
    Query = input().split()
    if int(Query[0]) == 1:
        state = not state
    else:
        if int(Query[1]) == 1:
            if state:
                ans.appendleft(Query[2])
            else:
                ans.append(Query[2])
        if int(Query[1]) == 2:
            if state:
                ans.append(Query[2])
            else:
                ans.appendleft(Query[2])

if state:
    print("".join(map(str, ans)))
else:
    print("".join(map(str, reversed(ans))))
