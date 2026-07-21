from collections import deque

s = input()
q=int(input())
deq = deque()
deq.append(s)
fl = False
for i in range(q):
    a=[i for i in input().split()]
    if a[0]=="1":
        fl = not fl
    else:
        if a[1]=="1":
            if fl:
                deq.append(a[2])
            else:
                deq.appendleft(a[2])
        else:
            if fl:
                deq.appendleft(a[2])
            else:
                deq.append(a[2])
if fl:
    s=''.join(deq)
    print(s[::-1])
else:
    print(''.join(deq))
