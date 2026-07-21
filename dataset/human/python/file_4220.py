import collections
N = int(input())
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
c = collections.Counter(prime_factorize(N))
d = list(c.items())
cnt = 0
for i in range(len(d)):
  for j in range(10 ** 8):
    if j * (j + 1) <= 2 * d[i][1] < (j + 1) * (j + 2):
      cnt += j
      break
    else:
      pass
print(cnt)
