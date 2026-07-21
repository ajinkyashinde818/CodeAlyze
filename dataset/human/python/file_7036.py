from collections import deque
s = deque(list(input()))
q = int(input())
query = [[1, 0, ''] for i in range(q)]
for i in range(q):
    tmp = input().split()
    if tmp[0] == '2':
        query[i][0] = int(tmp[0])
        query[i][1] = int(tmp[1])
        query[i][2] = tmp[2]

dire = 1
for i in range(q):
    if query[i][0] == 1:
        dire *= -1
    else:
        if (2*query[i][1]-3) * dire == 1:
            s.append(query[i][2])
        else:
            s.appendleft(query[i][2])

ans = ''.join(s)
if dire == 1:
    print(ans)
else:
    print(ans[::-1])
