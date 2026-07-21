from collections import deque

s = input()
Q = int(input())
query = [list(map(str, input().split())) for _ in range(Q)]

d = deque(s)

cnt = 0
for q in query:
    if q[0] == '1':
        cnt += 1
    else:
        if q[1] == '1':
            if cnt % 2:
                d.append(q[2])
            else:
                d.appendleft(q[2])
        else:
            if cnt % 2:
                d.appendleft(q[2])
            else:
                d.append(q[2])
        
d_list = list(d)
s = ''.join(d_list)
if cnt % 2 == 0:
    print(s)
else:
    print(s[::-1])
