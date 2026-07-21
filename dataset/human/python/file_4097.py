from collections import *
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

a = Counter(prime_factorize(int(input())))
count=0
for s in a.values():
    for m in range(40):
        if (m+1)*(m+2)/2>s:
            count+=m
            break
print(count)
