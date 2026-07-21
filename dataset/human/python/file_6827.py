from collections import deque
S = deque()
S.extend(input())
Q = int(input())
reverse = 0
for i in range(Q):
    list = input().split(' ')
    if list[0] == '1':
        reverse += 1
    elif list[1] == '1':
        if reverse % 2 == 1:
            S.append(list[2])
        else:
            S.appendleft(list[2])
    elif list[1] == '2':
        if reverse % 2 == 1:
            S.appendleft(list[2])
        else:
            S.append(list[2])
if reverse % 2 == 1:
    S.reverse()
ans = ''.join(S)
print(ans)
