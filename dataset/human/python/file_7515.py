from collections import deque

s = deque(input())
q = int(input())
flag = 1
for i in range(q):
    query = input().split()
    if query[0] == '1':
        flag *= -1
    elif query[1] == '1':
        if flag == 1:
            s.appendleft(query[2])
        else:
            s.append(query[2])
    elif query[1] == '2':
        if flag == -1:
            s.appendleft(query[2])
        else:
            s.append(query[2])
if flag == 1:
    print(''.join(s))
else:
    print(''.join(list(s)[::-1]))
