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
    return collections.Counter(a)

N=int(input())
if N == 1:
  print(0)
  exit()
ps = prime_factorize(N)

cnt = 0
for p in ps:
  c = ps[p]
  i = 1
  while c >= i:
    cnt += 1
    c -= i
    i += 1
print(cnt)
