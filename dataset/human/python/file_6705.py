S = input()

from collections import deque
S = deque(S)
Q = int(input())
query = [input().split() for _ in range(Q)]
reverse = 0
for i in range(Q):
    if query[i][0] == "1":
        reverse += 1
    else:
        if query[i][1] == "1":
            if reverse % 2 != 0:
                S.append(query[i][2])
            else:
                S.appendleft(query[i][2])
        else:
            if reverse % 2 != 0:
                S.appendleft(query[i][2])
            else:
                S.append(query[i][2])

result = "".join(S)
if reverse % 2 != 0:
    result = result[::-1]

print(result)
