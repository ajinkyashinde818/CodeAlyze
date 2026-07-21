import collections
n = int(input())

def function(n):
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
b = function(n)
c = collections.Counter(function(n))
ans = 0
for number in (c.values()):
  iter = 1
  flag = True
  while flag:
    number -= iter
    ans += 1
    iter += 1
    if number < iter:
      flag = False
print(ans)
