from collections import deque
s = list(input())
s = deque(s)
n = int(input())
cnt = 0
for i in range(n):
    q = list(map(str,input().split()))
    if q[0] == '1':
        cnt += 1
    else:
        if cnt % 2 == 0:
            if q[1] == '1':
                s.appendleft(q[2])
            else:
                s.append(q[2])
        else:
            if q[1] == '1':
                s.append(q[2])
            else:
                s.appendleft(q[2])
    #print(q)
if cnt % 2 != 0:
    s.reverse()
print(''.join(list(s)))
