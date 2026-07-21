import numpy as np
n=int(input())
def f(n):
  num=int(np.sqrt(2*n))
  while True:
    if num*(num+1)//2 > n:
      return num-1
    num+=1
p=[]
p_tf=[1 for i in range(int(np.sqrt(n))+1)]
p_tf=np.array(p_tf)
for i in range(2,int(np.sqrt(n))+1):
  if p_tf[i] and n%i==0:
    p.append(i)
    p_tf[i::i]-=1
p2=p.copy()
for i in p2:
  num=n//i
  t=True
  for j in p2:
    if num%j==0:
      t=False
  if t:
    p.append(num)
if len(p)==0 and n!=1:
  p=[n]
ans=0
for i in p:
  j=1
  while True:
    if n%i==0:
      n//=i
      j+=1
    else:
      j-=1
      break
  ans+=f(j)
print(ans)
