from math import floor,sqrt
N=int(input())

p = [1]*floor((10**6))
p[0]=p[1]=0
prime=[]
for i in range(2,len(p)):
    if p[i]==0:
        continue
    prime.append(i)
    for j in range(i*2,len(p),i):
        p[j]=0

ans=0
for x in prime:
    if N%x!=0:
        continue
    cnt=0
    while N%x==0:
        cnt+=1
        N//=x
    ans+=floor((-1+sqrt(1+8*cnt))/2)
print(ans+int(N!=1))
