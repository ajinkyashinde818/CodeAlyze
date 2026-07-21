import collections
def factorization(n):
    if n<2:
        return []
    
    prime_factor=[]
    
    for i in range(2,int(n**0.5)+1):
        while n%i==0:
            prime_factor.append(i)
            n//=i
            
    if n>1:
        prime_factor.append(n)
    return prime_factor

count=0
n=int(input())
 
c=collections.Counter(factorization(n))
d=list(c.values())
 
for v in c.values():
    for i in range(1,n):
        v-=i
        if v>=0:
            count+=1
        else:
            break
print(count)
