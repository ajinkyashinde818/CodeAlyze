import collections
S = list(input())
Q = int(input())

ans = collections.deque(S)
rev = False

for _ in range(Q):
    query = input().split()
    if query[0] == '1':
        rev = not rev
    else:
        if query[1] == '1':
            if rev:
                ans.append(query[2])
            else:
                ans.appendleft(query[2])
        else:
            if rev:
                ans.appendleft(query[2])
            else:
                ans.append(query[2])

if rev:
    print("".join(reversed(ans)))
else:
    print("".join(ans))
