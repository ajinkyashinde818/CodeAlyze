import math
N = int(input())
temp = N
total = 0
for n in range(2,int(-(-math.sqrt(N)//1))+1):
  count1 = 1
  count2 = 0
  while temp%n==0:
    temp = temp//n
    count2+=1
    if count2 == count1:
      count2 = 0
      count1 += 1
      total += 1
if temp != 1:
  total += 1
print(total)
