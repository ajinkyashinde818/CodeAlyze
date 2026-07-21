from collections import deque

s = list(str(input()))
q = int(input())
flag = True  # trueの時は反転が偶数回
deq = deque(s)
info = []
for i in range(q):
    info.append(list(input().split()))

for j in info:
    if j[0] == '1':
        if flag:
            flag = False
        else:
            flag = True
    else:
        if j[1] == '1' and flag:
            deq.appendleft(j[2])
        elif j[1] == '1' and (not flag):
            deq.append(j[2])
        elif j[1] == '2' and flag:
            deq.append(j[2])
        else:
            deq.appendleft(j[2])

if not flag:
    deq = reversed(deq)
deq = "".join(deq)
print(deq)
