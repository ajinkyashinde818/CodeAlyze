from collections import deque

S = list(str(input()))
Q = int(input())

d = deque(S)
R = 0

for i in range(Q):
    Query = str(input())
    if len(Query) == 1:
        R = (R+1)%2
    else:
        T,F,C = map(str,Query.split())

        if (R + int(F)) % 2 == 1:
            d.appendleft(C)
        else:
            d.append(C)

if R == 1:
    d.reverse()

for i in range(len(d)):
    print(d[i],end="")
