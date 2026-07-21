import collections
S = input()
Q = int(input())
q = collections.deque()
q.append(S)
inversion = True
for i in range(Q):
    Query = list(map(str, input().split()))
    if Query[0] == "1":
        inversion = not(inversion)
    elif Query[1] == "1":
        if inversion:
            q.appendleft(Query[2])
        else:
            q.append(Query[2])
    else:
        if inversion:
            q.append(Query[2])
        else:
            q.appendleft(Query[2])

if inversion:
    print("".join(q))
else:
    print("".join(q)[::-1])
