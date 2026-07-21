from collections import deque
X = input()
S = deque()
for e in X:
    S.append(e)
Q = int(input())
flip = 0
for i in range(Q):
    query = input()
    if query == str(1):
        flip += 1
    else:
        f = int(query[2])
        c = query[-1]
        if f == 1:
            if flip%2 == 1:
                S.append(c)
            else:
                S.appendleft(c)
        else:
            if flip%2 == 1:
                S.appendleft(c)
            else:
                S.append(c)
S = "".join(S)
if flip%2 == 1:
    print(S[::-1])
else:
    print(S)
