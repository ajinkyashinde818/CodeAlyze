S = input()
Q = int(input())
Q_list = list()
for i in range(Q):
    Q_list.append(input().split())
 
from collections import deque
def operate(i):
    global count, str_list
    if Q_list[i][0] == '1':
        count += 1
    else:
        if count % 2 == 0:
            if Q_list[i][1] == '1':
                str_list.appendleft(Q_list[i][2])
            else:
                str_list.append(Q_list[i][2])
        else:
            if Q_list[i][1] == '1':
                str_list.append(Q_list[i][2])
            else:
                str_list.appendleft(Q_list[i][2])
 
check = 0
for i in range(Q):
    if Q_list[i][0] == '1':
        check += 1
 
S_list = [i for i in S]
if check % 2 == 1:
    S_list = list(reversed(S_list))
 
S_n = ''.join(S_list)
 
str_list = deque()
str_list.append(S_n)
count = check%2
for i in range(Q):
    operate(i)
print(''.join(str_list))
