import math

N = int(input())

p = 2
counter = 0
while N != 1:
 if p > math.sqrt(N):
  counter += 1
  break
 ind = 0
 n = -1
 while N % p == 0:
  N //= p
  ind += 1
 if ind == 0:
  p += 1
  continue
 while (n+1)*(n+2)//2 <= ind:
  n += 1
 counter += n
 p += 1

print(counter)
