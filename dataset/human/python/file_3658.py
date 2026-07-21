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
if N == 1:
  print(0)
else:
  c = collections.Counter(prime_factorize(N))
  ans = 0
  for num in c.values():
    tmp = 0
    for i in range(1,num+1):
      if tmp + i <= num:
        tmp +=i
        ans += 1
      else:
        break
  print (ans)
