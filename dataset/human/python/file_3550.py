def resolve():
	from collections import Counter

	def prime_factorize(n):
		a = []
		i = 2
		while i < n**(1/2) + 1:
			if n%i == 0:
				n //= i
				a.append(i)
			else:
				i += 1
		if n != 1:
			a.append(n)
		return a
	
	def cnt(x):
	    ans = 0
	    i = 1
	    while True:
	        ans += i
	        if ans > x:
	            return i-1
	        i += 1
	        
	n = int(input())
	ans = 0

	a = Counter(prime_factorize(n))
	for i in a.values():
	    ans += cnt(i)

	print(ans)

resolve()
