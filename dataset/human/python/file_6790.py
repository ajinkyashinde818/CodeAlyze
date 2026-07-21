f=input
from collections import deque
s=deque(f())
n=int(f())
t=0
for i in range(n):
  q=f()
  if q[0]=='1': t^=1 #control the t, kalo t=1 reverse , t=0 no change
  else:
    if int(q[2])==1 and t==1: #t=1 and q[2]=1 , so append from end , krn q[2]=1 append from start 
      s.append(q[4])
    elif int(q[2])==2 and t==1: #t=1 and q[2]=1 , so  append from front , krn q[2]=2 from end
      s.appendleft(q[4])
    elif int(q[2])==1 and t==0: #t=1 and q[2]=1 , sono mama
      s.appendleft(q[4])
    elif int(q[2])==2 and t==0: #t=1 and q[2]=1 , sono mama
      s.append(q[4])
print(''.join([s,list(s)[::-1]][t])) 
#to get first when nothing change or end when t=1 so exchange
