import collections
import numpy as np

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

N = int(input())

c = collections.Counter(prime_factorize(N))
X = np.array([])
for i in c.values():
    X = np.append(X,i)

ans = 0

for i in range(1,10**6):
    if len(X) == 0:
        print(ans)
        exit()
    X -= i
    X = X[X>=0]
    ans += len(X)
