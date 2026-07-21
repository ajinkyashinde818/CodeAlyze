import collections
import math
from statistics import mode
N = int(input())
c = 0
ans = 0
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
e = []
for i in set(prime_factorize(N)):
	e.append(prime_factorize(N).count(i))

for i in e:
	for j in range(math.ceil(math.sqrt(2*i))+1):
		if (j+1)*(j+2)//2 > i:
			break
		c += 1
	ans += c
	c = 0
print(ans)
