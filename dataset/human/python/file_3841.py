N = int(input())
from collections import Counter
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
  
l = prime_factorize(N)
ans = 0
for k,v in Counter(l).items():
  i = 1
  while v>=i:
    v-=i
    ans += 1
    i += 1
    
print(ans)
