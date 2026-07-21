import sys
from collections import deque
import collections
import numpy as np

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

def hantei(n):
    i = 0
    if n == 1 or n==2:
        return 1
    while (i+1)*i/2<=n:
        i+=1
    return i-1

c = collections.Counter(prime_factorize(n))
ans = 0
#print(c)

for i in c.values():
    #print("val=",i)
    ans += hantei(i)
print(ans)
