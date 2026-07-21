from collections import defaultdict
import math
dt = defaultdict(int)
def primeFactors(n): 
      
    while n % 2 == 0: 
        dt[2]+=1 
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        while n % i== 0: 
            dt[i]+=1 
            n = n //i 
              
    if n > 2: 
        dt[n]+=1
def how(n):
    i=1 
    while (i*(i+1))//2 <= n:
        i+=1 
    i-=1
    return i
        
n = int(input())
primeFactors(n)
ans = 0 
#print(dt)
for key in dt.keys():
    ans+= how(dt[key])
    #print(how(dt[key]))
print(ans)
