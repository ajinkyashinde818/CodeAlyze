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

import collections
count = 0
N = int(input())
c = collections.Counter(prime_factorize(N))

for i in c:
    p = i
    while (N%i==0):
        N /= i
        i *= p
        count += 1
#         print(N,i)
    if (N == 1):
        break
        
print(count)
