import collections

S = collections.deque(list(input()))
Q = int(input())
rev = 0
for i in range(0, Q):
    query = list(input().split())
    if query[0] == "1":
        rev = rev+1
    else:
        if query[1] == "1":
            if rev%2 == 0:
                S.appendleft(query[2])
            else:
                S.append(query[2])
        else:
            if rev%2 == 0:
                S.append(query[2])
            else:
                S.appendleft(query[2])
if rev%2 == 0:
    for i in S:
        print (i, end = "")
else:
    for i in reversed(S):
        print (i, end = "")
