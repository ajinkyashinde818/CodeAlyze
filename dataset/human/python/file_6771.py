from collections import deque

s=deque(input())
q=int(input())
t=[list(map(str,input().split())) for i in range(q)]

def head(a):
    s.appendleft(a)
    
def end(a):
    s.append(a)

x=True
for i in range(q):
    if len(t[i])==1:
        x=not x
    else:
        if x==True:
            if t[i][1]=='1':
                head(t[i][2])
            else:
                end(t[i][2])
        else:
            if t[i][1]=='1':
                end(t[i][2])
            else:
                head(t[i][2])
if x==True:
    print(''.join(s))
else:
    s.reverse()
    print(''.join(s))
