import math
N = int(input())

list = []


while(N%2==0):
  list.append(2)
  N = N//2
  
f = 3

while(f*f <= N):
  if(N%f==0):
    list.append(f)
    N = N // f
  else:
    f += 2
if(N!=1):
  list.append(N)
count = 0
while(len(list)>0):
  k=0
  #mu = []
  max_num = list.count(list[0])
  num = 1
  while(num <= max_num):
    count += 1
    max_num -= num
    num += 1
  for i in range(list.count(list[k])):
    list.remove(list[k])
  
print(count)
