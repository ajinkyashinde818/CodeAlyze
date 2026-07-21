from collections import deque

s = deque(input())
n = int(input())
q_list = [input().split() for i in range(n)]
count = 1
for i in q_list:
    if i[0] == '1':
        count *= -1
    else:
        if i[1] == '1':
            if count == 1:
                s.appendleft(i[2])
            else:
                s.append(i[2])
        else:
            if count == 1:
                s.append(i[2])
            else:
                s.appendleft(i[2])
if count != 1:
    s.reverse()
print(*s, sep='')
