import collections
s = input()
_q = int(input())
q = collections.deque(s)

rev = False
for _ in range(_q):
    *query, = map(str, input().split())

    if query[0] == "1":
        rev = not rev
        continue

    f, c = query[1], query[2]

    if rev ^ (f == "1"):
        q.appendleft(c)
    else:
        q.append(c)

if rev:
    q.reverse()

print("".join(q))
