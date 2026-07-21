import sys
import math
import collections
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
N=int(input())
a=0
if N==1:
  print(0)
  sys.exit()
c = collections.Counter(prime_factorize(N))
L=c.values()
L=list(map(int,L))
for i in range(len(L)):
  q=int(math.sqrt(L[i]))
  for j in range(q,N+1):
    if j*(j+1)//2>L[i]:
      t=(j-1)
      break
    elif j*(j+1)//2==L[i]:
      t=j
      break
  a+=t
print(a)
