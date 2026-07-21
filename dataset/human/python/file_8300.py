def solve(ar):
  n = len(ar)
  if sum(ar) % (n * (n+1) // 2) != 0:
    return False
  l = sum(ar) // (n * (n+1) // 2)
  ar2 = []
  for i in range(n-1):
    if i == 0:
      ar2.append(ar[0])
    else:
      ar2.append(ar[i] - ar[i-1] - l)

  b = [0]
  for i in range(1, n-1):
    if ar2[i] % n != 0:
      return False
    bi = - ar2[i] // n
    if bi < 0:
      return False
    b.append(bi)

  a = ar[0]
  a2 = l
  for i in range(1, n-1):
    a -= b[i] * (n-i+1)
    a2 -= b[i]

  bn = a - a2
  b0 = a2 - bn
  if bn < 0 or b0 < 0:
    return False

  return True

n = int(input())
ar = [int(x) for x in input().split()]
if solve(ar):
  print("YES")
else:
  print("NO")
