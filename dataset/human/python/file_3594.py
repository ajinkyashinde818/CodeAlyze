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

def getTime(v):
  time = 0
  total = 0
  while total <= v:
    time += 1
    total += time
  return (time - 1)

N = int(input())
result = 0
c = collections.Counter(prime_factorize(N))
for k in c.keys():
  result += getTime(c[k])
  
print(result)
