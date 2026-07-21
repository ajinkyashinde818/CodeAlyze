from math import floor

r, g, b, n = map(int, input().split())
r, g, b = sorted([r, g, b])[::-1]

cnt = 0
for r0 in range(floor(n // r)+1):
  for g0 in range(floor((n-r*r0)// g)+1):
    sum = r * r0 + g * g0
    if sum > n:
      continue
    if (n - sum) % b == 0:
      cnt += 1

print(cnt)
