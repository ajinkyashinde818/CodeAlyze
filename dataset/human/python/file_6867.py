from collections import deque
s = deque(input())
q = int(input())
flag = True
for i in range(q):
    x = input()
    if x == '1':
        flag = not flag
    else :
        if x[2] == '1' and flag :
            s.appendleft(x[4])
        elif x[2] == '2' and not flag :
            s.appendleft(x[4])
        else :
            s.append(x[4])
if flag:
    for i in s :
        print(i, end='')
else :
    for i in range(1, len(s)+1):
        print(s[-i], end='')
print('')
