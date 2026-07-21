from collections import deque

d = deque(list(input()))
flag = 1
for _ in range(int(input())):
    a = input()
    if a[0] == '1':
        flag *= -1
    elif a[2] == '1' and flag == 1:
        d.appendleft(a[4])
    elif a[2] == '1' and flag == -1:
        d.append(a[4])
    elif a[2] == '2' and flag == 1:
        d.append(a[4])
    else:
        d.appendleft(a[4])
if flag == -1:
    d.reverse()
print(''.join(d))
