import math
import collections

n = int(input())
s = 0
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

m = 0
l = collections.Counter(prime_factorize(n))
l2 = list(dict.values(l))
#for i in range(len(l2)):
#    s += int((math.sqrt(1 + 9 * l2[i])-1)/2)
for i in range(len(l2)):
    for j in range(n):
        if l2[i] >= j*(j+1)/2:
            m = j
        else:
            break


    s += m


print(s)
