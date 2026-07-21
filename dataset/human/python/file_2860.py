import math
def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(math.sqrt(n))+1):
    if temp%i == 0:
      cnt = 0
      while temp%i == 0:
        cnt += 1
        temp //= i
      arr.append([i, cnt])
  if temp != 1:
    arr.append([temp, 1])
  if arr == []:
    arr.append([n, 1])
  return arr

n = int(input())
factors = factorization(n)
res = 0
for j,cnt in factors:
  if j == 1: continue
  i = 1
  while cnt >= i:
    cnt -= i
    i += 1
    res += 1

print(res)
