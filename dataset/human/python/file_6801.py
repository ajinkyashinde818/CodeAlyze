from collections import deque

S = input()
Q = int(input())

ans = deque()
ans.append(S)
reverse = False

for i in range(Q):
    x = list(input().split())
    if int(x[0]) == 1:
        reverse = not reverse
        continue
    if int(x[1]) == 1 and not reverse:
        ans.appendleft(x[2])
    elif int(x[1]) == 2 and reverse:
        ans.appendleft(x[2])
    else:
        ans.append(x[2])

ans = ''.join(ans)

if reverse:
    print(ans[::-1])
else:
    print(ans)
