import math
N=int(input())
L=[]
for i in range(2,int(math.sqrt(N))):
    if N%i==0:
        c=0
        while N%i==0:
            N/=i
            c+=1
        L.append(c)
if N!=1:
    L.append(1)
ans=0
for i in L:
    for n in range(10):
        if (n*(n+1))//2>i:
            ans+=n-1
            break
print(ans)
