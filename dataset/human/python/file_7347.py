from collections import deque
S = deque(input())
Q = int(input())
is_reversed = 1
for _ in range(Q):
    query = list(input().split())
    if query[0] == "1":
        is_reversed *= -1
    
    else:
        if is_reversed == 1:
            if query[1] == "1":
                S.appendleft(query[2])
            else:
                S.append(query[2])
        else:
            if query[1] == "2":
                S.appendleft(query[2])
            else:
                S.append(query[2])

S = "".join(S)
print(S[::is_reversed])
