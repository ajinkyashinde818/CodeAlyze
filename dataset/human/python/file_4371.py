n=int(input())
from math import sqrt as S 
pf=[]
for i in range(2,int(S(n))+1):
    if n%i==0:
        c=0 
        while n%i==0:
            n//=i 
            c+=1 
        pf.append([i,c])
if n>1:
    pf.append([n,1])
cnt=0 
def search(x):
    i=1 
    while i*(i+1)//2<=x:
        i+=1 
    return i-1 
for x in range(len(pf)):
    a=pf[x][0]
    b=pf[x][1]
    cnt+=search(b)
print(cnt)
