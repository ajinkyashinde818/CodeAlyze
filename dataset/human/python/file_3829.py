from collections import Counter
from itertools import accumulate
B=[i for i in range(101)]
B=list(accumulate(B))

N=int(input())
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

d=Counter(prime_factorize(N))
k=d.keys()
ans=0
for i in k:
  a=1
  while d[i]>=B[a]:
    ans+=1
    a+=1
print(ans)
