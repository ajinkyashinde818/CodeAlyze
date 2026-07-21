k,s = [int(i) for i in input().split()]
def a(n):
  return int(n * (n + 1) / 2)
  
if s <= k:
  print(a(s + 1))
elif s >= 2 * k and s <= 3 * k:
  print(a(3 * k - s + 1))
elif s > k and s < 2 * k:
  print(a(s + 1) - 3 * a(s - k))
else:
  print(0)
