from collections import deque
 
S = deque(list(input()))
Q = int(input())
rvs = False
 
for q in range(Q):
    query = list(input().split())
    if len(query) > 1:
        if query[1] == "1":
            if rvs:
                S.append(query[2])
            else:
                S.appendleft(query[2])
        elif query[1] == "2":
            if rvs:
                S.appendleft(query[2])
            else:
                S.append(query[2])
    else:
        rvs = not (rvs)
 
if rvs:
    S.reverse()
 
print("".join(S))
