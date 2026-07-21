import collections
import sys

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

Z = prime_factorize(N)

if not Z:
    print(0)
    sys.exit(0)

P = collections.Counter(Z)

#print(P)

x = 0

for i in P.values():
    #print(i)
    y = 0
    z = 0
    for j in range(1, i+1):
        y = y + j
        z += 1
        #print(i, y, z)
        if y >= i:
            if y > i:
                z -= 1
            break
    
    x = x + z

print(x)
