import math 
def primeFactors(n): 
    l=[]  
    while n % 2 == 0: 
        l.append(2)
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            l.append(int(i))
            n = n / i 
    if n > 2: 
        l.append(int(n))
    return l
n=int(input())
l=primeFactors(n)
l.sort()
s=set(l)
d={}
for i in s:
    d[i]=0
for i in l:
    d[i]=d[i]+1
ans=0
for i,j in d.items():
    c=0
    while j>0:
        if j>=c+1:
            c=c+1
        j=j-c
    ans=ans+c
print(ans)
