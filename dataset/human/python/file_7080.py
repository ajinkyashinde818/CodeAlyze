from collections import deque

s = input()
q = int(input())

deq = deque([s])
flag = 1
for i in range(q):
    query = input().split()
    if query[0]==str(1):
        flag*=-1 
    if query[0]==str(2):
        x = 1 if query[1]==str(1) else -1
        if flag*x==1:
            deq.appendleft(query[2])
        else:
            deq.append(query[2])

if flag==-1:
    print(''.join(deq)[::-1])
else:
    print(''.join(deq))
