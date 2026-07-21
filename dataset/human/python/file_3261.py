from collections import Counter
N = int(input())
factors = []
i = 2
while N > 1:
  if N < i * i:
    factors.append(N)
    break
  while N % i == 0:
    factors.append(i)
    N //= i
  i += 1

ans = 0
for count in Counter(factors).values():
  i = 1
  while count >= i:
    count -= i
    i += 1
    ans += 1
print(ans)
