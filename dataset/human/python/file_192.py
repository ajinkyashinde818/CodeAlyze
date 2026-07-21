import math
r,g,b,n = map(int, input().split())

cnt = 0
s = 0
for i in range(math.ceil(n/r)+1):
  for j in range(math.ceil(n/g)+1):
    s = r*i+g*j
    if s > n:
      break
    if (n-s)%b == 0:
      cnt += 1
print (cnt)
