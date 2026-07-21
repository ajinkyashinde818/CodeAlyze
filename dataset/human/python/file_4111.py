def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def countNewZ(count, countZ):
  current = (countZ * (countZ + 1)) / 2
  if(current <= count):
    countZ += 1
    return countNewZ(count, countZ)
  else:
    return countZ - 1

n = int(input())
primeFactors = prime_factors(n)
unique = set(primeFactors)
z = 0
for prime in unique:
  count = primeFactors.count(prime)
  z += countNewZ(count, 0)
print(z)
