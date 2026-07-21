import math 
def primeFactors(n): 
    a=[]  
    while n % 2 == 0: 
        a.append(2) 
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):  
        while n % i== 0: 
            a.append(i) 
            n = n // i  
    if n > 2: 
        a.append(n) 
    return a    
import math as m
n=int(input())
x=0
i=0
a=list(set(primeFactors(n)))
ans=0
p=1
flag=False
while(i<len(a)):
    j=a[i]
    x=a[i]
    while(True):
        if n%j==0:  
            ans+=1 
            n//=j
            j*=x
        else:
            break
        if p==n:
            flag=True
            break
    if(flag):break    
    i+=1         
print(ans)
