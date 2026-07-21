def make_divisors(n):
    divisors=[]
    for i in range(1,int(n**0.5)+1):
        if n%i==0:
            divisors.append(i)
            if i!=n//i:
                divisors.append(n//i)
    divisors.sort()
    return divisors


def prime_factorize(n):
    a=[]
    while n%2==0:
        a.append(2)
        n //=2
    f=3
    while f**2<=n:
        if n%f==0:
            a.append(f)
            n //=f
        else:f +=2
    if n!=1:a.append(n)
    return a


n=int(input())
prime=make_divisors(n)
prime=[i for i in prime if len(set(prime_factorize(i)))==1]
A=set()
for i in prime:
    if i==1:continue
    num,e=i,1
    while num<=n:
        A.add(num)
        e +=1
        num=i**e
cnt=0
for i in sorted(A):
    if n%i==0:
        cnt +=1
        n //=i
print(cnt)
