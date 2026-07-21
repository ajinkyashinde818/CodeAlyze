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
tmp = prime_factorize(N)
import collections
C = collections.Counter(tmp)
count = 0
for key in C.keys():
    tmp = C[key]
    i = 0
    while True:
        i += 1
        if tmp >= i:
            tmp -= i
            count += 1
        else:
            break
print(count)
