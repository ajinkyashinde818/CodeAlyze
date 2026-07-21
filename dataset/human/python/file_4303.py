import math
n=int(input())
ans=0
for i in range(2,int(math.sqrt(n)+1)):
    if n%i==0:
        prime=i
        power=0
        while n%i==0:
            n=n//i
            power+=1
        st=1
        while st<=power:
            ans+=1
            power-=st
            st+=1
if n>1:
    ans+=1
print(ans)
