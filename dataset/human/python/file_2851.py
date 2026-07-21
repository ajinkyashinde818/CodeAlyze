n = int(input())

import math
def primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]
  
ps = primes(10**6)
ans = 0
for p in ps:
  d = 1
  while n%(p**d) == 0:
    #print(n, p**d, p, d)
    n = n//(p**d)
    ans += 1
    d += 1
    
if n>10**6:
  print(ans + 1)
else:
  print(ans)
