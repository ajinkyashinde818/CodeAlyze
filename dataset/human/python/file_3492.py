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
A = collections.Counter(prime_factorize(N))
ans = 0
for i in A.values():
  for j in range(40):
    if ((j + 1) * (j + 2) / 2 <= i) and ((j + 2) * (j + 3) / 2 > i):
      ans = ans + j + 1
print(ans)
