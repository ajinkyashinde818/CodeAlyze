from collections import Counter
n = int(input())
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
a = Counter(prime_factorize(n))
ans = 0
for i in a.values():
  for j in range(1,1000):
    di = j*(j+1)/2
    if di > i:
      ans += j-1
      break
print(ans)
