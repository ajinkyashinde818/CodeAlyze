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
import collections
n=int(input())

c = collections.Counter(prime_factorize(n))
count=0
for k,v in c.items():
  i=3
  count+=1
  if v>=3:
    while v>2:
      count+=1
      v-=i
      i+=1
print(count)
