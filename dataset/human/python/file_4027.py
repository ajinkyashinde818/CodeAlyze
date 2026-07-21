m = int(input())
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

c = collections.Counter(prime_factorize(m))
#print(c)
#print(list(c.values()))
#print(list(c.values())[1])
keys =[]
k = len(list(c.values()))

for i in range(k):
  for j in range(45):
    if j*(j+1)/2 > list(c.values())[i]:
      break
  keys.append(j-1)

#print(keys)
print(sum(keys))
