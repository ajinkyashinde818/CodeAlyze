from collections import deque


S = deque(list(input()))
Q = int(input())
queries = []
for _ in range(Q):
    query = input().split()
    if len(query) == 3:
        queries.append([int(x) for x in query[:2]] + [query[2]])
    else:
        if len(queries[-1]) == 1:
            queries.pop()
        else:
            queries.append([int(x) for x in query])
p = True
count = 0
for query in queries:
    if len(query) == 3:
        if p:
            if query[1] == 1:
                S.appendleft(query[2])
            else:
                S.append(query[2])
        else:
            if query[1] == 1:
                S.append(query[2])
            else:
                S.appendleft(query[2])
    else:
        p = not p
        count += 1

if count % 2:
    S.reverse()
print(''.join(S))
