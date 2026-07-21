import math
N = int(input())
max_D = int(2 + math.sqrt(N))
count = []
ans = 1
for i in range(2, max_D):
   if N % i == 0:
      count.append(0)
      while N % i == 0:
         N = N // i
         count[-1] += 1
   if N < i:
      ans = 0
      break
l = len(count)
for i in range(l):
   E = 2*count[i]
   j = 0
   while j * (j + 1) <= E:
      j += 1
   ans += j - 1
print(ans)
