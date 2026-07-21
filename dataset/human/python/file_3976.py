import collections
N=int(input())
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

def count_n(x):
    n=1
    while True:
        m=(1+n)*n/2
        if m>x:
            n-=1
            break
        n+=1
    return n


c = collections.Counter(prime_factorize(N))
d = c.values()
co=0
for i in d:
    co+=count_n(i)

if N==1:
    print(0)
else:
    print(co)
