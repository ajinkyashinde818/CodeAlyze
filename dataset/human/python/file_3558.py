n = int(input())
nn = n
def divisor(n): #nの約数を全て求める
  i = 1
  table = []
  while i * i <= n:
    if n%i == 0:
      table.append(i)
      table.append(n//i)
    i += 1
  table = list(set(table))
  return table

import math
from collections import Counter


prime_count = Counter()
for i in range(2, math.ceil(math.sqrt(n))+1):
  while n % i == 0:
    n /= i
    prime_count[i] += 1
if n > 1:
  prime_count[int(n)] += 1

if len(prime_count) == 0:
  print(0)
  exit()

z = 0
zz = 0
cnt = 0
for k, v in prime_count.items():
  for i in range(1, v+1):
    if nn % pow(k, i) == 0:
      cnt += 1
      nn = nn // pow(k, i)
    else:
      break

print(cnt)
