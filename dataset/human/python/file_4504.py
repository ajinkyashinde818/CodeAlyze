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

arr = factorize(N)

count = 0
for p,e in arr:
  i = 1
  while True:
    if e < i:
      break
    e -= i
    i += 1
    count += 1      

print(count)
