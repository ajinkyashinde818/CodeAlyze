from math import gcd
from collections import Counter

n=int(input())
if n==1:
    print(0)
    exit()

def factorize(n):
    factor=[]
    for i in range(2,int(n**0.5)+1):
        while n%i==0:
            n=n//i
            factor.append(i)
    if n!=1:
        factor.append(n)
    return factor

count = Counter(factorize(n))
ans=0
for key in count:
    sum=0
    for i in range(1,100000):
        sum+=i
        if count[key] >= sum and count[key] < sum+i+1:
            ans+=i
            break
        else:
            continue
print(ans)
