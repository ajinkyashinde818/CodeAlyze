import collections

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
  
def nannko(s):
  i = 1
  while s > i-1:
    s -= i
    i +=1
  return i-1

c = collections.Counter(prime_factorize(n))
kosuu = list(c.values())

ans = 0
for i in kosuu:
  ans += nannko(i)

print(ans)
