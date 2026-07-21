import math

n = int(input())

factors = []

m2 = 0
while n > 1 and n % 2 == 0:
	m2 += 1
	n //= 2
if m2:
	factors.append((2,m2))

m3 = 0
while n > 1 and n % 3 == 0:
	m3 += 1
	n //= 3
if m3:
	factors.append((3,m3))

i = 5
l = int(math.sqrt(n)) + 1

while n > 1 and i < l:
	if n % i == 0:
		m = 0
		while n > 1 and n%i == 0:
			m += 1
			n //= i
		factors.append((i, m))
	i += 2

if n != 1:
	factors.append((n,1))

ans = 0

for _, m in factors:
	count = 0
	s = 0
	while s < m:
		count += 1
		s += count
	ans += count if s == m else count - 1

print(ans)
