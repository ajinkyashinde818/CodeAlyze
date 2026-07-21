from collections import deque

s = deque(input())
query_num = int(input())
query_li = list()
for _ in range(query_num):
    query_li.append(input().split())

rev_flag = False
for query in query_li:
    if query[0] == '1':
        rev_flag = not rev_flag
    elif (query[1] == '1' and rev_flag) or (query[1] == '2' and not rev_flag):
        s.append(query[2])
    else:
        s.appendleft(query[2])

if rev_flag:
    print(''.join(deque(reversed(s))))
else:
    print(''.join(s))
