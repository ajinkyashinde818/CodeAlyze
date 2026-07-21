from collections import deque

d = deque(list(input()))
q = int(input())
flag = 1
for i in range(q):
    query = input().split()
    if query[0] == '1':
        flag = - flag
    elif query[0] == '2':
        if flag == 1:
            if query[1] == '1':
                d.appendleft(query[2])
            elif query[1] == '2':
                d.append(query[2])
        else:
            if query[1] == '1':
                d.append(query[2])
            elif query[1] == '2':
                d.appendleft(query[2])
if flag == -1:
    d.reverse()
print(''.join(list(d)))
