from collections import deque

s = input()
n = int(input())
ans = deque(s)

div = True
for i in range(n):
    q = input().split(' ')
    if q[0] == '1':
        div = not div
    elif (q[1] == '1' and div) or (q[1] == '2' and not div):
        ans.appendleft(q[2])
    else:
        ans.append(q[2])

if div:
    print(''.join(ans))
else:
    print(''.join(reversed(ans)))
