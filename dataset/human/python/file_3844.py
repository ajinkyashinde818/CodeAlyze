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

n = int(input())

c = collections.Counter(prime_factorize(n))
ans = 0
for k, v in c.items():
  i = 1
  while True:
    v -= i
    if v < 0:
      break
    ans += 1
    i += 1

print(ans)
