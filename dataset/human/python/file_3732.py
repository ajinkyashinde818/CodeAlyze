import math
n = int(input())

index = 2
array = [0] * math.ceil(math.sqrt(n)+1)
while index <= math.sqrt(n):
  while n % index == 0:
    array[index] += 1 
    n //= index
    
  index += 1
  
ans = 0
if n >= len(array):
  ans += 1
elif n != 1:
  array[n] += 1
  
for i in range(len(array)):
  index = 1
  while index <= array[i]:
    array[i] -= index
    index += 1
    ans += 1
    
print(ans)
