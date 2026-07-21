from collections import deque
s = input()
Q = int(input())
que = deque(s)
cnt = 0
for i in range(Q):
    q = input().split()
    if q[0] == '1':
        cnt += 1
    else:
        reverse = cnt % 2
        if q[1] == '1':
            if reverse == 0:
                s = que.appendleft(q[2])
            else:
                s = que.append(q[2])
        else:
            if reverse == 0:
                s = que.append(q[2])
            else:
                s = que.appendleft(q[2])

ans = ''.join(que)
if cnt % 2 == 0:
    print(ans)
else:
    print(ans[::-1])
