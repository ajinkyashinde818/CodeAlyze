import math
n = int(input())
MAX = int(math.sqrt(n)) + 1

a = [0]*MAX

for i in range(2, MAX):
  while n % i == 0:
    n /= i
    a[i] += 1

if n != 1:
  ans = 1
else:
  ans = 0
  
for i in a:
  for j in range(MAX):
    p = int(j * (j+1) / 2)
    if i < p:
      ans += j - 1
      break
print(ans)
