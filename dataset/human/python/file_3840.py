n=int(input())

def sieve(x):
  p=[2]
  b=[1]*x
  for i in range(2,x,2):  b[i]=0
  for i in range(3,x,2):
    if b[i]:
      p+=[i]
      for j in range(2*i,x,i): b[j]=0
  return p
def prime_factor(x):
  d={}
  for i in sieve(int(x**0.5)+1):
    while x%i<1:  x//=i;  d[i]=d.get(i,0)+1
    if x<2: break
  if x>1: d[x]=1
  return d

d=prime_factor(n)
a=0
for i in d.values():
  t=c=0
  while t+c<i: c+=1; t+=c
  a+=c
print(a)
