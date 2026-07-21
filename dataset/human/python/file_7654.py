from collections import deque

s = deque(input().split())
n = int(input())
query_li = (input().split() for i in range(n))

flag = 1

for query in query_li:
    if int(query[0]) == 1:
        flag = flag * -1
    else:
        if int(query[1]) == 1:
            if flag == 1:
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if flag == 1:
                s.append(query[2])
            else:
                s.appendleft(query[2])

s = ''.join(s)
if flag == -1:
    s = s[::-1]

print(s)
