from collections import deque

s = input()
q = int(input())
Q = [input() for _ in range(q)]

s = deque(list(s))
insert = s.appendleft
append = s.append
flag = True

for query in Q:
    if query[0] == '1':
        flag = not flag
    else:
        if (query[2] == '1' and flag) or (query[2] == '2' and not flag):
            insert(query[4])
        else:
            append(query[4])

if not flag:
    s.reverse()

print(*s, sep='')
