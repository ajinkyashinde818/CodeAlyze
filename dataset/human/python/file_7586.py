from collections import deque
s=deque(list(input()))

Q=int(input())
append_flag=False
Q_=[]

for q in range(Q):
    T = list(input().split())
    if T[0]=='2':
        append_flag=True
    if append_flag:
        Q_.append(T)
        
rev=1
rev_num=0
for q in Q_:
    if q[0]=='1':
        rev = -1*rev
        rev_num+=1
    elif rev == 1:
        if q[1]=='1':
            s.appendleft(q[2])
        elif q[1]=='2':
            s.append(q[2])
    elif rev == -1:
        if q[1]=='2':
            s.appendleft(q[2])
        elif q[1]=='1':
            s.append(q[2])

s=list(s)
if rev_num%2 != 0:
    s.reverse()
    
print(''.join(s))
