N=int(input())

def prime_factorize(N):
    a = []
    while N % 2 == 0:
        a.append(2)
        N //= 2
    f = 3
    while f * f <= N:
        if N % f == 0:
            a.append(f)
            N //= f
        else:
            f += 2
    if N != 1:
        a.append(N)
    return a

import collections
c = collections.Counter(prime_factorize(N))

X=list(c.values())
ans=0
for i in range(len(c.values())):
    for j in range(1,100):
        if X[i]<(j+1)*j/2:
            ans+=j-1
            break

print(ans)
