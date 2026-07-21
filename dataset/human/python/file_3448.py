def doit(n):
	if(n == 1):
		return 0
	c = 0
	temp = n
	for p in range(2, int(n ** 0.5) + 1):
		if temp % p == 0:
			e = 0
			while temp % p == 0:
				e += 1
				temp //= p
			c += int(0.5 * (-1 + (1 + 8 * e) ** 0.5))

	if temp == n:
		c += 1
	elif temp != 1:
		c += 1

	return c

print(doit(int(input())))
