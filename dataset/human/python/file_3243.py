import collections
N=int(input())
if N==1:
    print(0)
    exit()
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
c = collections.Counter(prime_factorize(N)) 
s=list(set(prime_factorize(N)))
ans=0
def a(n):
    return (1/2)*n*(n+1)
def f(n):
    ans=0
    x=1
    while n>=a(x):
        x+=1
        ans+=1
    return ans
for i in s:
    x=c[i]
    ans+=f(x)
print(ans)
