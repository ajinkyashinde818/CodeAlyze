import collections

n=int(input())

p=n
e=1
count=0
            

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

for i in list(set(prime_factorize(n))):
    #print(i)
    e=1
    while i**e<=p:
        a=i**e
        #print("aは",a)
        #print("nは",n)
        if n%a==0:
            n=n/a
            count+=1
        e+=1

print(count)
