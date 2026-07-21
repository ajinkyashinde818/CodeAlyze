n=int(input())
k=n
dic={}
import math
for i in range(2,math.floor(math.sqrt(n))):
  for j in range(10**10):
    if n%i==0:
      if i in dic:
        dic[i]+=1
      else:
        dic[i]=1
      n=n//i
    else:
      break

count=0
if k!=1:
  if not dic or n!=1:
    count+=1

while dic:
  keep=1
  x=dic.popitem()
  num=x[1]
  for i in range(1000):
    if num>=keep:
      num-=keep
      count+=1
      keep+=1
    else:
      break
print(count)
