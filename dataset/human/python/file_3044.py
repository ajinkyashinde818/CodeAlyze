from math import sqrt,gcd,ceil 
def ii():return int(input())
def mi():return map(float,input().split())
def li():return list(mi())
def si():return input()

n=ii()
ans=0
for i in range(2,int(sqrt(n))+1):
    f=0
    while(n%i==0):
        n//=i
        f+=1
    c=1
    c1=1
    while(c<=f):
        ans+=1
        c1+=1
        c+=c1
if(n>1):
    ans+=1
print(ans)
