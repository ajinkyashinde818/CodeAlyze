def factorize(n):
  b = 2
  fct = []
  while b * b <= n:
    while n % b == 0:
      n //= b
      fct.append(b)
    b = b + 1
  if n > 1:
    fct.append(n)
  return fct

def getpattern(x):
  pattern = 0
  d = 0
  for i in range(1, 1000000):
    d += i
    if x < d:
      break
    pattern += 1
  return pattern

n = int(input())
f = factorize(n)
fu = set(factorize(n))
r = 0
for fui in fu:
  r += getpattern(f.count(fui))
print(r)
