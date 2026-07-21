def factorization(n):
  arr = []
  tmp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if tmp % i == 0:
      cnt = 0
      while tmp % i == 0:
        cnt += 1
        tmp //= i
      arr.append([i, cnt])
  if tmp != 1:
    arr.append([tmp, 1])
  if arr == [] and n != 1:
    arr.append([n, 1])
  return arr

n = int(input())
c = factorization(n)
ans = 0

for k, v in c:
  cnt = 1
  while v >= cnt:
    v -= cnt
    cnt += 1
  ans += (cnt - 1)

print(ans)
