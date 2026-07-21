def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
      if temp%i==0:
          cnt=0
          while temp%i==0:
              cnt+=1
              temp //= i
          arr.append([i, cnt])

  if temp!=1:
      arr.append([temp, 1])

  if arr==[]:
      arr.append([n, 1])

  return arr

import sys

z = int(input())
dividers = factorization(z)

# zが1の場合
if (z == 1):
  print(0)
  sys.exit()
# そうでない場合
else:
  ans = 0
  for divider in dividers:
    i = 0
    while i*(i+1)/2 <= divider[1]:
      i += 1
    ans += i - 1

print(ans)
