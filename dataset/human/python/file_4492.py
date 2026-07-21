import math
from collections import Counter

def prime_factorize(n):
    factor = []
    thre = int(math.sqrt(n)) + 1
    for num in range(2,thre):
      if num%2 == 0 and num != 2:
        continue
      while n % num == 0:
        n //= num
        factor.append(num)
    if n != 1:
      factor.append(n)
    return Counter(factor)

def func(n):
  i = 1
  tmp = 0
  while True:
    tmp += i
    if tmp > n:
      i -= 1
      break
    elif tmp == n:
      break
    i += 1
  return i

N = int(input())

result = 0
for key, value in prime_factorize(N).items():
    result += func(value)

print(result)
