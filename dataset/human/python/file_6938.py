from collections import deque
S=list(input())
Q=int(input())
A=deque()
O=deque()
flag=0
for i in range(Q):
    q=input()
    if q=='1':
        if flag==0:
            flag=1
        else:
            flag=0
    else:
        t,f,c=q.split()
        if flag==0:
            if f=='1':
                A.appendleft(c)
            else:
                O.append(c)
        else:
            if f=='1':
                O.append(c)
            else:
                A.appendleft(c)
if flag==0:
    R=list(A)+S+list(O)
else:
    R=list(O)[::-1]+S[::-1]+list(A)[::-1]  
print(''.join(R))
