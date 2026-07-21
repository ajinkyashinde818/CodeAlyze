import collections
n=int(input())

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
  
c = collections.Counter(prime_factorize(n))
cc=list(c.keys())
def countcheck(x):
  a=0
  aa=0
  b=[1]
  while x>=a:
    a+=b[-1]
    c=b[-1]+1
    b.append(c)
    if x>=a:
      aa+=1
    
  return aa

ans=0

for x in range(len(cc)):
  dd=cc[x]
  d=c[dd]
  e=countcheck(d)
  ans+=e
  
print(ans)
