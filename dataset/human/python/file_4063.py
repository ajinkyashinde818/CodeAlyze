import collections

n = int(input())

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

P = collections.Counter(prime_factorize(n))

def counter(n):
    i = 1
    counter = 0
    while True:
        n-=i
        if n<0:
            break
        else:
            counter += 1
            i += 1
    return counter
  
ans = 0
for p in P.values():
  ans += counter(p)

print(ans)
