import collections

def pf(n):
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
  
a=int(input())
pl=pf(a)
c=collections.Counter(pl)
nl=list(c.values())

re=0
for x in nl:
  for y in range(1,100):
    if x*2<(y+1)*(y+2):
      re+=y
      break
      
print(re)
