S=input()
Q=int(input())
lst=[]
for _ in range(Q):
    lst.append(input().split())

import collections

str=list(S)
d=collections.deque(str)

right=True
for operation in lst:
    if operation[0]=='1':
       right=not right

    else:
        if right==True and operation[1]=='1' or right==False and operation[1]=='2':
            d.appendleft(operation[2])
        else:
            d.append(operation[2])
str=list(d)
if right==True:
    print(''.join(str))
else:
    print(''.join(str[::-1]))
