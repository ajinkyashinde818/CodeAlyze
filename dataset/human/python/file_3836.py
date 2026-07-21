import math
n=int(input())
sqn=int(math.sqrt(n))
p=[1]*int(2*sqn+20)
p[0]=0;p[1]=0
for i in range(2,sqn):
    if p[i]:
        for j in range(2,sqn//i+1):
            p[i*j]=0

p=[i for i in range(sqn+7) if p[i]]
f={}
for pi in p:
    if n%pi==0:
        cnt=1
        n//=pi
        while n%pi==0:
            cnt+=1
            n//=pi
        f[pi]=cnt
    
#print(f)
if n>1:
    f[n]=1
ans=0
for k in f:
    tmp=1
    while (tmp+1)*(tmp+2)//2<=f[k]:
        tmp+=1
    ans+=tmp
    #print(ans,tmp,k,f[k])
print(ans)
