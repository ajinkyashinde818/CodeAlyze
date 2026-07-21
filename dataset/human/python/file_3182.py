import math
l = []
n = int(input())
for i in range(2,int(math.sqrt(n))+1):
  flg = 0
  while n % i == 0:
    if flg == 0:
      l.append(1)
      flg = 1
    else:
      l[-1] += 1
    n = n//i

if n != 1:
  l.append(1)

ans = 0
for i in range(len(l)):
  c = 1
  while l[i] - c >= 0:
    l[i] -= c
    c += 1
    ans += 1

print(ans)
