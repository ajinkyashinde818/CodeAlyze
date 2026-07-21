n=int(input())
def prime(n):
  dic={}
  f=2
  m=n
  while f*f<=m:
    r=0
    while n%f==0:
      n//=f
      r+=1
    if r>0:
      dic[f]=r
    f+=1
  if n!=1:
    dic[n]=1
  return dic

def counter(dic):
  ans=0
  for val in dic.values():
    i=1
    while i*(i+3)/2<val:
      i+=1
    ans+=i
  return ans

print(counter(prime(n)))
