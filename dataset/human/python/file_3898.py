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
pf = prime_factorize(N)
m = 1
ext = {}
c = 0
l = 1
if len(pf) > 0:
  l = pf[0]
while True:
  if len(pf) == 0:
    break
  i = pf.pop()
  if l != i:
    l = i
    m = 1
  m = m * i
  if not m in ext:
    ext[m] = m
    m = 1
    c += 1
print(c)
