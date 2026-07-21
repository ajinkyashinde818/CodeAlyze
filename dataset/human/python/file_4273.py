from  collections import defaultdict

n=int(input())

def prime_factorize(n):
    d=defaultdict(int) 
    while n % 2 == 0:
        d[2]+=1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            d[f]+=1
            n //= f
        else:
            f += 2
    if n != 1:
        d[n]+=1
    return d

u=prime_factorize(n) 
cnt=0
for key,value in u.items():
    r=10**12
    l=0 
    while r-l>1:
        mid=(r+l)//2
        if mid*(mid+1)//2<=value:
            l=mid 
        else:
            r=mid
    cnt+=l
print(cnt)
