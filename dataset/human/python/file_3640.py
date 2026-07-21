import collections
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
n=int(input())
c=collections.Counter(prime_factorize(n))
d=list(c.values())
s=0
x=1
for i in d:
  while i>=x*(x+1)/2:
    s+=1
    x+=1
  x=1
print(s)
