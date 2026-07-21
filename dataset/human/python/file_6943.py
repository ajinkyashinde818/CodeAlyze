from collections import deque

t = input()
s = deque()
for i in range(len(t)): s.append(t[i])
q = int(input())
flg = False
for i in range(q):
    query = input()
    if query[0] == '1': flg = not flg
    else:
        t,f,c = query.split()
        if flg:
            s.appendleft(c) if f=='2' else s.append(c)
        else:
            s.appendleft(c) if f=='1' else s.append(c)
if flg: s = reversed(s)
print(''.join(s))
