from sys import stdin
import math

a=int(stdin.readline())
PP=0
K=0

if a==1:
    print(0)
    K=1
L=list()


for b in range(2,int(math.floor(math.sqrt(a)))+1):
    count=0
    if a%b==0:
        while a%b==0:
            count+=1
            a=a/b
    if count>0:
       L.append(count)


if len(L)==0 and K==0:
    print(1)
    PP=1

if a!=1:
    L.append(1)

sum=0

for k in range(0,len(L)):
    p=L[k]
    sum+=int(math.floor((-1+math.sqrt(1+8*p))/2))


if PP==0 and K==0:
   print(sum)
