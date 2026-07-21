import collections
s = collections.deque(input())
rev = 0
for i in range(int(input())):
    q = list(input().split())
    if len(q) == 1:
        rev += 1
    else:
        if q[1] == "1":
            if rev % 2 == 0:
                s.appendleft(q[2])
            else:
                s.append(q[2])
        else:
            if rev % 2 == 1:
                s.appendleft(q[2])
            else:
                s.append(q[2])
if rev % 2 == 1:
    s.reverse()
print("".join(s))
