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

def countLoop(n):
  if n == 1 :
    return 1
  cnt = 0
  for i in range(1,n+1):
    if n >= i :
      n -= i
      cnt += 1
    else :
      return cnt

n = int(input())

c =  collections.Counter(prime_factorize(n))

cnt = 0
for x in c:
  cnt += countLoop(c[x])

print(cnt)
