__DEUBG__ = 0

import decimal
import math
import sys
from collections import *
from itertools import *

N = int(input())

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

if __DEUBG__:
	print(prime_factors(N))

z = set()
p = None

while N > 1:
	if __DEUBG__:
		print('while')
		print(N)
	for n in prime_factors(N):
		if p:
			if (p % n) == 0:
				p *= n
			else:
				p = n
			if p in z:
				pass
			else:
				N //= p
				z.add(p)
				p = None
				break
		else:
			p = n
			if p in z:
				pass
			else:
				N //= p
				z.add(p)
				p = None
				break
	else:
		break

print(len(z))
