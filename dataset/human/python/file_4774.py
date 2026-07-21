def is_b_larger_than_a(a, b):
  n = min(len(a), len(b))
  for i in range(n):
    if ord(a[i]) > ord(b[i]):
      return False
    if ord(a[i]) < ord(b[i]):
      return True
  return len(a) < len(b)

s = sorted(input(), reverse=False)
t = sorted(input(), reverse=True)

if is_b_larger_than_a(s, t):
  print("Yes")
else:
  print("No")
