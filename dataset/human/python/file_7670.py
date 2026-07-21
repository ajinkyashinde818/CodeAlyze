from collections import deque

s = deque(list(input()))
q = int(input())
flg = 1
for i in range(q):
    array = input().split(' ')
    if array[0] == '1':
        flg *= -1
    elif array[0] == '2':
        if array[1] == '1' and flg == 1 or array[1] == '2' and flg == -1:
            s.appendleft(array[2])
        else:
            s.append(array[2])

s = list(s)
if flg == -1:
    s = s[::-1]

s = ''.join(s)
print(s)
