import math

a,b = map(int,input().split())

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

a_ = prime_factorize(a)
b_ = prime_factorize(b)

for i in a_:
    if i in b_:
        b_.remove(i)

for j in b_:
    a *= j

print(a)
