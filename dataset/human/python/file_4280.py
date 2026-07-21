def prime_factorize(n):
    a=[]
    while n%2==0:
        a.append(2)
        n//=2
    f=3
    while f*f<=n:
        if n%f==0:
            a.append(f)
            n//=f
        else:
            f+=2
    if n!=1:
        a.append(n)
    return a
l=[0]
ii=0
for i in range(1,11):
    ii+=i
    l.append(ii)

n=int(input())
import collections
c=collections.Counter(prime_factorize(n))
count=0
for i in c.values():
    for j in range(10):
        if i>=l[j] and i<l[j+1]:
            count+=j
print(count)
