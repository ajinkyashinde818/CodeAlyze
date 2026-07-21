import math

li=list(map(int,input().split()))
max_=max(li[0],li[1])

a=[0 for i in range(max_+1)]
b=[0 for i in range(max_+1)]

for i in range(2,li[0]+1):
  while(li[0]%i==0 and li[0]!=1):
    li[0]//=i
    a[i]+=1
for i in range(2,li[1]+1):
  while(li[1]%i==0 and li[1]!=1):
    li[1]//=i
    b[i]+=1

result=1
for i in range(1,max_+1):
  max_num=max(a[i],b[i])
  result*=i**max_num
print(result)
