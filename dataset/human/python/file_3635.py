import math
N=int(input())
def hantei(u):
  if u==1:
    return 1
  for i in range(1,u+1):
    if (1/2)*i**2+(1/2)*i>u:
      return int(i-1)
    else:
      continue
   
a=[0]*int(math.sqrt(N))
for i in range(2,int(math.sqrt(N))+1):
  while N%i==0:
    N=N//i
    a[i-1]=a[i-1]+1
c=0
if N!=1:
  c+=1
for t in range(len(a)):
  if a[t]!=0:
    c+=hantei(a[t])
print(c)
