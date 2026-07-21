from collections import deque

s = deque(list(input()))
q = int(input())
head = 0

for i in range(q):
    L = list(input().split())
    if L[0] == '1' :
        head = (head + 1)%2
    if L[0] == '2' :
        if head == 0:
            if L[1] == '1' :
                s.appendleft(L[2])
            if L[1] == '2' :
                s.append(L[2])
        if head == 1:
            if L[1] == '1' :
                s.append(L[2])
            if L[1] == '2' :
                s.appendleft(L[2])
if head == 0:
    print(''.join(s))
else: 
    print(''.join(reversed(s)))
