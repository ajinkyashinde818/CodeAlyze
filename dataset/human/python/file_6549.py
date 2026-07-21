from collections import deque

s = deque(input())
q = int(input())
flag = True
for _ in range(q):
    query = input().split()
    if query[0] == "1":
        flag = not flag
    else:
        if (query[1] == "1" and flag) or (query[1] == "2" and not flag):
            s.appendleft(query[2])
        else:
            s.append(query[2])
if not flag:
    s.reverse()
print(''.join(s))
