n = int(input())

from collections import Counter

factors = []
i = 2
while n > 1:
   if n < i * i:
      factors.append(n)
      break
   while n % i == 0:
      factors.append(i)
      n //= i
   i += 1

ans = 0
for cnt in Counter(factors).values():
   i = 1
   while cnt >= i:
      cnt -= i
      i += 1
      ans += 1
print(ans)
