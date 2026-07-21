import numpy as np
import collections

n = int(input())

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

fact = collections.Counter(prime_factorize(n))
# print("f", fact)
can = 0

for a in fact.values():
    a_i = a
    # print("a", a)
    i = 0
    while(a_i >= 0):
        i += 1
        a_i -= i
        # print("i", i)
    can += (i-1)

print(can)
