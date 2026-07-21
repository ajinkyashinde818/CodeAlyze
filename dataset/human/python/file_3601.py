import numpy as np

def is_prime(a):
  if a == 1:
    return False
  
  for i in range(2, 1+int(a**0.5)):
    if a % i == 0:
      return False
  return True

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

n = int(input())

ans = 0
divisors = make_divisors(n)
for d in divisors[1:]:
  if d > n:
    break
  if is_prime(n):
    ans += 1
    break
    
  tmp_divisors = make_divisors(d)
  for p in tmp_divisors[1:]:
    if not is_prime(p):
      continue
    tmp = np.log(d)/np.log(p)
    if tmp > 0 and tmp == int(tmp) and n % d == 0:
      n = n/d
      ans += 1
      break

print(ans)
