def f(n):
  p=[]
  if n%2==0:
    c=0
    while n%2==0:
      c+=1
      n/=2
    p.append(c)
  for i in range(3,int(n**0.5)+1,2):
    if n%i==0:
      c=0
      while n%i==0:
        c+=1
        n/=i
      p.append(c)
  if n!=1:
    p.append(1)
  return p
  
N=int(input())
p=f(N)
r=0
while p:
  r+=int(((8*p.pop()+1)**0.5-1)/2)
print(r)
