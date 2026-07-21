from collections import deque

s = deque((str(input())))
loop = int(input())

rev = 0
for i in range(loop):
    queries = input().split()
    if len(queries) == 1:
        rev = (rev+1) % 2
    else:
        type = int(queries[1])
        c = str(queries[2])
        if (type + rev) % 2 == 1:
            s.appendleft(c)
        else:
            s.append(c)
if rev == 1:
    s.reverse()
print("".join(list(s)))
