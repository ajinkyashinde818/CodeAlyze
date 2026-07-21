from math import *
from collections import Counter
def factorize(n):
	res = []
	while n%2 == 0:
		res.append(2)
		n = n//2
	for i in range(3,int(sqrt(n))+1,2):
		while n%i == 0:
			res.append(i)
			n = n//i
	if n > 2:
		res.append(n)

	return set(res)

n = int(input())
primes = factorize(n)
ans = 0
for i in primes:
	c = i
	while n%c == 0:
		n = n // c
		c = c * i
		ans+=1
print(ans)
