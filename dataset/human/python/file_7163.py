from collections import deque
s = list(input())
q = int(input())
rev = 0
revcnt = 0
s_q = deque(s)
for _ in range(q):
    query = list(map(str, input().split()))
    if query[0] == "1":
        revcnt += 1
        if rev == 0:
            rev = 1
        elif rev == 1:
            rev = 0

    elif query[0] == "2":
        if rev == 0:
            if query[1] == "1":
                s_q.appendleft(query[2])
            elif query[1] == "2":
                s_q.append(query[2])
        else:
            if query[1] == "1":
                s_q.append(query[2])
            elif query[1] == "2":
                s_q.appendleft(query[2])
s = list(s_q)
if revcnt%2 == 0:
    print("".join(s))
else:
    print("".join(s[::-1]))
