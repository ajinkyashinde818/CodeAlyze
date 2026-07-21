N = int(input())
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
x = factorize(N)
counter = 0
for item in x:
  if item[1]==1:
    counter += 1
  else:
    temp = item[1]
    i = 1
    while temp > 0:
      temp -= i
      i += 1
      if temp >= 0:
        counter += 1
print(counter)
