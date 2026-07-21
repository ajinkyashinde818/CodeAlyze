from collections import *


def factors(n):
    div = 2
    l = []
    while div * div <= n:
        if n % div == 0:
            l.append(div)
            n //= div
        else:
            div += 1
    if n != 1:
        l.append(n)
    return Counter(l)


l = factors(int(input()))
z = 0
for k, v in l.items():
    i = 1
    while v >= i:
        z += 1
        v -= i
        i += 1
print(z)
