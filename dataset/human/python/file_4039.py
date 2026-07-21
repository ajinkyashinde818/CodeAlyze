a=[]
for i in range(51):
    a+=[i]*(i+1)

def prime_factor(n):
    ass=[]
    for i in range(2,int(n**0.5)+1):
        while n%i==0:
            ass.append(i)
            n=n//i
    if n!=1:
        ass.append(n)
    return ass
    
from collections import Counter
c=Counter(prime_factor(int(input())))
ans=0
for i in c.values():
    ans+=a[i]
print(ans)
