import math
n=int(input())
if n==1:
  print(0)
else:
  x=[]
  for i in range(2,int(math.sqrt(n)+1)):
    if n%i==0:
      x.append(i)
      if n//i!=i:
        x.append(n//i)
  x.append(n)
  x.sort()
  sosu=[]
  for i in x:
    for j in range(2,int(math.sqrt(i))+1):
      if i%j==0:
        break
    else:
      sosu.append(i)
  ans=0
  for i in x:
    if n//i>=1:
      for j in sosu:
        for k in range(1,int(math.log(i,j))+1):
          if j**k==i:
            if n%i==0:
              ans+=1
              n/=i
              break
    else:
      break
  print(ans)
