from collections import deque

S = input()
Q = int(input())
ans = deque(S)
reverse = False

for _ in range(Q):
    query = input().split()
    if query[0] == "1":
        reverse = not reverse
    if query[0] == "2":
        F, C = query[1:]
        if (F == "1" and not reverse) or (F == "2" and reverse):
            ans.appendleft(C)
        else:
            ans.append(C)

if reverse:
    print("".join(reversed(ans)))
else:
    print("".join(ans))
