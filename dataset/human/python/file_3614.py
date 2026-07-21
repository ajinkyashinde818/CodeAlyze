import collections
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

if N == 1:
	print(0)
	exit()

c = collections.Counter(prime_factorize(N))

ans = 0
for m in c.values():
	n = 1
	while (n*(n+1))//2 <= m:
		ans += 1
		n += 1
print(ans)
