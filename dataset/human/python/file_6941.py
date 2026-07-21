from collections import deque
sl = list(input())
q = int(input())
dl = deque(sl)
r = 0
for _ in range(q):
    query = list(map(str, input().split()))
    if len(query) == 1:
        r += 1
    else:
        if r % 2 == 0:
            if query[1] == "1":
                dl.appendleft(query[2])
            else:
                dl.append(query[2])
        else:
            if query[1] == "1":
                dl.append(query[2])
            else:
                dl.appendleft(query[2])
if r % 2 == 1:
    dl.reverse()
print("".join(dl))
