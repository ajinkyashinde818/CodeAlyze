from collections import deque

s = input()
q = int(input())

deq = deque(s)
rev = False

for _ in range(q):
    query = input().split()
    t = query[0]
    if t == "1":
        rev = not rev
        continue
    f = query[1]
    c = query[2]
    if not rev and f == "2" or rev and f == "1":
        deq.append(c)
    else:
        deq.appendleft(c)
if rev:
    deq = reversed(deq)
print("".join(deq))
