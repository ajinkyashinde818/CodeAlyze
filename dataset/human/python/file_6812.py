from collections import deque


S = deque(input())
Q = int(input())
is_reversed = False

for _ in range(Q):
    Query = input().split()
    if Query[0] == "1":
        is_reversed = not is_reversed
    else:
        F, C = int(Query[1]), Query[2]
        if is_reversed:
            F = 3 - F
        if F == 1:
                S.appendleft(C)
        else:
                S.append(C)

if is_reversed:
    S.reverse()
print("".join(S))
