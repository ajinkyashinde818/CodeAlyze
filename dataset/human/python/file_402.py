import math
N=int(input())
s=input().split()
s_l=[]
i=0
count=0
while i<N:
       p=0
       q=0
       if int(s[i])<0:
              p=int(s[i])*(-1)
              s_l.append(p)
              count+=1
       else:
              q=int(s[i])
              s_l.append(q) 
       i+=1
ans1=sum(s_l)
ans2=sum(s_l)-min(s_l)*2

if count%2==0:
       print(ans1)
else:
       print(ans2)
