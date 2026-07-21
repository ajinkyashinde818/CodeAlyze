from collections import deque

s = deque(input())
q = int(input())
 
me = 1#1:sei  -1:gyaku
for i in range(q):
    t = input().split()
    if t[0] == '1':
        me *= -1
            
    else:# 0=2
        if t[1]=='1':#1=1
            s.appendleft(t[2]) if me == 1 else s.append(t[2])
        else:#1=2
            s.append(t[2]) if me == 1 else s.appendleft(t[2])
s= list(s) 
if me != 1:
    s = s[::-1]
print(''.join(s))
