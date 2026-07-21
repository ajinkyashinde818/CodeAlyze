from collections import deque

S = input()
Q = int(input())
query = [input() for _ in range(Q)]

S = deque(S)

inv = 0
for q in query:
    if q[0] == "1":
        inv += 1
    else:
        _, f, c = q.split()
        if f == "1":
            if inv % 2 == 0:
                S.appendleft(c)
            else:
                S.append(c)
        else:
            if inv % 2 == 0:
                S.append(c)
            else:
                S.appendleft(c)
S = "".join(S)
print(S if inv % 2 == 0 else S[::-1])
