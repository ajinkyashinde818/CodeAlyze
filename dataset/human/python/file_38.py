import math
r,g,b,n = map(int,input().split())
 
ans = 0
for i in range(math.ceil(n/r)+1):
  for j in range(math.ceil((n-r*i)/g)+1):
    if (n - r*i - g*j)%b == 0 and n - r*i - g*j >= 0:
      ans += 1
print(ans)
