def isprime(x):
    for i in range(2,int(x**0.5)+1):
        if x%i==0:
            return False
    return x!=1


dic={}
n=int(input())
t=int(n**0.5)+1
for i in range(2,t):
    cnt=0
    while n%i==0:
        cnt+=1
        n//=i
    dic[i]=cnt
if n!=1:
    dic[n]=1
ans=0
for i in dic:
    x=dic[i]
    r=(-1+(1+8*x)**0.5)//2
    ans+=r
print(int(ans))
