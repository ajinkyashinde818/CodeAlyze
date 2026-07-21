import math

n=int(input())

kotae=[]
temp=n

for i in range(2,int(math.sqrt(n)//1)+1):
  if temp%i==0:
    count=0
    while temp%i==0:
      temp=temp/i
      count+=1
    kotae.append([i,count])
if temp!=1:
  kotae.append([n,1])

answer=0
for i in range(len(kotae)):
  kaisuu=0
  taisyo=kotae[i][1]
  while taisyo>=0:
    kaisuu+=1
    taisyo-=kaisuu
  answer+=kaisuu-1

print(answer)
