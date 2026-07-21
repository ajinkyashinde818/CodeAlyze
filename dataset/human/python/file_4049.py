def factorisation(n):
  res = dict()
  i = 1
  while i * i <= n:
    i += 1
    if n % i != 0:
      continue
    res[i] = 0
    while n % i == 0:
      n //= i
      res[i] += 1
  if n > 1:
    res[n] = 1
  return res

n = int(input())
ind = factorisation(n)
ans = 0
for p in ind.keys():
  a = 1
  while ind[p] >= a:
    ind[p] -= a
    ans += 1
    a += 1
print(ans)
