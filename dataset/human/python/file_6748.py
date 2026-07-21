from collections import deque


S = deque(input())
Q = int(input())
QUERY = [input().split(" ") for i in range(Q)]
reverse_f = 0

for query in QUERY:
    if query[0] == "1":#反転
        reverse_f = (reverse_f+1)%2
    else:#=="2"
        if query[1] == "1":
            if reverse_f:
                S.append(query[2])
            else:
                S.appendleft(query[2])

        else:#=="2"
            if reverse_f:
                S.appendleft(query[2])
            else:
                S.append(query[2])

if reverse_f:
    S.reverse()
print("".join(list(S)))
