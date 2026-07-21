from collections import deque

s = input()
s = list(s)
q = int(input())
query = list(list(input().split()) for _ in range(q))

d = deque(s)

rs = False

for i in range(q):
    qry = query[i]
    if qry[0] == '1':
        rs = not rs
    else:
        if qry[1] == '1':
            if not rs:
                d.appendleft(qry[2])
            else:
                d.append(qry[2])
        else:
            if not rs:
                d.append(qry[2])
            else:
                d.appendleft(qry[2])
                
d = list(d)
if rs:
    d.reverse()
                
d = ''.join(d)
print(d)
