from collections import deque
s = input()
d = deque(s)
q = int(input())
flag = 0
for i in range(q):
    tfc = input().split()
    if tfc[0] == '1':
        if flag == 0:
            flag = 1
        else:
            flag = 0
    else:
        if flag == 0:
            if int(tfc[1]) == 1:
                d.appendleft(tfc[2])
#                 print('appendleft:', d)
            else:
                d.append(tfc[2])
#                 print('append:', d)
        else:
            if int(tfc[1]) == 1:
                d.append(tfc[2])
#                 print('append:', d)
            else:
                d.appendleft(tfc[2])
#                 print('appendleft:', d)
if flag == 0:
    print(''.join(d))
else:
    print(''.join(reversed(d)))
