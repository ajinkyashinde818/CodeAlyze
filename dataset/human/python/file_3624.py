from collections import defaultdict as dd
from math import sqrt
d=dd(int)
def pr(n): 
    while n % 2 == 0:
        d[2]+=1
        n = n / 2
    for i in range(3,int(sqrt(n))+1,2): 
        while n % i== 0: 
            d[i]+=1
            n = n / i 
    if n > 2: 
        d[n]+=1

n=int(input())
pr(n)
ans=0
for i in d:
    ans+=(sqrt(1+8*d[i])-1)//2
print(int(ans))
