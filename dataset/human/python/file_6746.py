from collections import deque
S = deque(input())
Q = int(input())

reverse = False
for _ in range(Q):
    query = input().split()
    if query[0] == "1":
        reverse = not reverse
    else:
        tail = bool(int(query[1]) - 1) ^ reverse
        c = query[2]
        if tail:
            S.append(c)
        else:
            S.appendleft(c)

print("".join(reversed(S)) if reverse else "".join(S))
