import math

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors[1:] + upper_divisors[::-1]

def isPrime(n):
  if n == 2:
    return True
  if n % 2 == 0:
    return False

  m = math.floor(math.sqrt(n)) + 1
  for p in range(3, m, 2):
      if n % p == 0:
        return False
  return True


n = int(input())
if n == 1:
    print(0)
    exit()
if isPrime(n):
    print(1)
    exit()
div = make_divisors(n)
ans = 0
for i in range(len(div)):
    if n % div[i] == 0:
        divdiv = make_divisors(div[i])
        if div[i] == divdiv[0] ** len(set(divdiv)):
            if isPrime(divdiv[0]):
                n //= div[i]
                ans += 1
    if n == 1:
        break
print(ans)
