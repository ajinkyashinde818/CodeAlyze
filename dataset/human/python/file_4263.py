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

def triangle(n):
  i=1
  while i*(i+1)/2<=n:
    i+=1
  return i-1
  
import collections
prime_prod=collections.Counter(prime_factorize(int(input())))
print(sum([triangle(i) for i in list(prime_prod.values())]))
