import numpy as np
import sys
A=a=int(input())
count=2
samenumcount=0
y=[]
 
if A==1:
    print(0)
    sys.exit()
 
while A!=1 and count<np.sqrt(a):
    if A%count==0:
        samenumcount+=1
        y.append(count**samenumcount)
        A=A/count
    else:
        count+=1
        samenumcount=0
if A!=1:
    y.append(A)
y.sort()
count2=0
for i in y:
    if a==1:
      break
    if a%i==0:
        a=a/i
        count2+=1
 
if count2==0:
    count2+=1

print(count2)
