import math

N = int(input())

primes = {}
i = 2
sqrt_N = math.floor(math.sqrt(N))
while i <= sqrt_N:
	if N % i == 0:
		if i in primes:
			primes[i] += 1
		else:
			primes[i] = 1
		N //= i
		sqrt_N = math.floor(math.sqrt(N))
	else:
		i += 1

if N != 1:
	if N in primes:
		primes[N] += 1
	else:
		primes[N] = 1

count = 0
for c in primes.values():
	i = 1
	while i <= c:
		count += 1
		c -= i
		i += 1
print(count)
