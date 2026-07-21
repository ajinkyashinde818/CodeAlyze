import sys

n = int(input())
a = [int(x) for x in input().strip().split()]

total = sum(a)
nn = n * (n + 1) / 2
if total % nn != 0 :
  print('NO')
else:
  m = total / nn
  l = 0
  flg = True
  for i in range(n):
    j = i - 1
    if i == 0:
      j = n - 1
    if a[j] + m - a[i] < 0 or (a[j] + m - a[i]) % n != 0:
      flg = False
      break
    l += (a[j] + m - a[i]) / n

  if flg == True:
    print('YES')
  else:
    print('NO')
