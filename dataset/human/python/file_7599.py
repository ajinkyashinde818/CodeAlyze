from collections import deque
S = input()
s = list(S)
d = deque()
for i in range(len(s)):
    d.append(s[i])
Q = int(input())
p = [[0 for i in range(3)]for j in range(Q)]
x = 1
for i in range(Q):
    p[i] = list(map(str,input().split()))
def add(s,x,f,c):
    if x ==1:
        if f == 1:
            s.appendleft(str(c))
        else:
            s.append(str(c))
    else:
        if f == 1:
            s.append(str(c))
        else:
            s.appendleft(str(c))
for i in range(Q):
    if int(p[i][0]) == 1:
        x = -x
    else:
        add(d,x,int(p[i][1]),p[i][2])
if x == 1:
    print(''.join(d))
else:
    d.reverse()
    print(''.join(d))
