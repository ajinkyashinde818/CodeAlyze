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
N = int(input())
c = collections.Counter(prime_factorize(N))
d = list(c.values())
ans = 0
for j in range(len(d)):
  for i in range(1,40):
    k = i*(i+1)/2
    if d[j] == k:
      ans += i
      break
    elif d[j] < k:
      ans += i-1
      break
    else:
      continue
print(ans)
