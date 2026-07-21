A, B = map(int, input().split())

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

a = prime_factorize(A)
b = prime_factorize(B)

common = []
only_a = []
for i in a:
  if i in b:
    common.append(i)
    b.remove(i)
  else:
    only_a.append(i)

p = 1
for x in common + only_a + b:
  p *= x
print(p)
