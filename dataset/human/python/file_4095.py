def factorize(n):
    fct = []  # prime factor
    b, e = 2, 0  # base, exponent
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            fct.append((b, e))
        b, e = b + 1, 0
    if n > 1:
        fct.append((n, 1))
    return fct

import math

def kaisa(x):
  first = math.floor(math.sqrt(x*2))
  if x*2 >= first*(first+1):
    return first
  else:
    return first-1

n = int(input())
soinsu = factorize(n) 

res = 0
for i in soinsu:
  res = res + kaisa(i[1])
print(res)
