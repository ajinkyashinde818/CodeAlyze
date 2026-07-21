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
    
n=int(input())
f=prime_factorize(n)
if len(f)==0:
  print(0)
  exit()
s=set(f)
r=0

def func(m):
  r=0
  for ii in range(m):
    if m>=ii+1:
      m-=(ii+1)
      r+=1
      #print(ii+1,m,r)
    else:
      break
  return r

for ii in s:
  m=f.count(ii)
  fm=func(m)
  #print("ii",ii,fm)
  r+=fm
  
print(r)
