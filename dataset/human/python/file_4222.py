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

N = int(input())
rlt = 0
c = collections.Counter(prime_factorize(N))

for i in c:
  k = 0
  j = 1
  while k <= c[i]:
    k += j
    j += 1
  rlt += (j-2)
  
print(rlt)
