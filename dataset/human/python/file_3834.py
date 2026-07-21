import collections
import math

n = int(input())
B = [1,3,6,10,15,21,28,36,45,55,66,78,91,105]
ans = 0

def is_prime(n):
    if n == 1: return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False
    return True
if is_prime(n) == True:
  print(1)
  exit()

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

c = collections.Counter(prime_factorize(n))  
for v in c.values():
  for j in range(len(B)):
    if v < B[j]:
      ans += j
      break
      
print(ans)
