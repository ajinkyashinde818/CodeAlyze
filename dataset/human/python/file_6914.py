from collections import deque
s = input()
q = int(input())
qu = [input().split() for _ in range(q)]
le = deque()
ri = deque()
for i in range(len(s)):
    le.append(s[i])
    ri.appendleft(s[i])
x = 1
for i in range(q):
    if qu[i] == ['1']:
        x *= -1
    elif x == 1:
        ci = qu[i][2]
        if qu[i][1] == '1':
            le.appendleft(ci)
            ri.append(ci)
        else: 
            le.append(ci)
            ri.appendleft(ci)
    else: 
        ci = qu[i][2]
        if qu[i][1] == '1':
            le.append(ci)
            ri.appendleft(ci)
        else: 
            le.appendleft(ci)
            ri.append(ci)
y = ''
if x == 1:
    for i in le:
        y += i
else: 
    for i in ri:
        y += i
print(y)
