import sys
from collections import Counter
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def prime_factorise(n):
    a=[]
    while n%2==0:
        n//=2
        a.append(2)
    f=3
    while f*f<=n:
        if n%f==0:
            n//=f
            a.append(f)
        else:
            f+=2
    if n!=1:
        a.append(n)
    return a

n=int(input())
factors = Counter(prime_factorise(n))
ans=0
for i in factors.values():
    temp=1
    while i-temp>=0:
        i-=temp
        temp+=1
        ans+=1
print(ans)
