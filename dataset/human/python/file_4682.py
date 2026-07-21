def from_mcxi(s):
	n = 0
	t = 1
	for c in s:
		if c == 'm':
			n += t*1000
		elif c == 'c':
			n += t*100
		elif c == 'x':
			n += t*10
		elif c == 'i':
			n += t*1
		else:
			t = int(c)
		if c in 'mcxi':
			t = 1
	return n

def to_mcxi(n):
	s = ''
	if (n // 1000) > 0:
		if (n // 1000) > 1:
			s += str(n // 1000)
		s += 'm'
	if (n % 1000 // 100) > 0:
		if (n % 1000 // 100) > 1:
			s += str(n % 1000 // 100)
		s += 'c'
	if (n % 100 // 10) > 0:
		if (n % 100 // 10) > 1:
			s += str(n % 100 // 10)
		s += 'x'
	if (n % 10) > 0:
		if (n % 10) > 1:
			s += str(n % 10)
		s += 'i'
	return s

n = int(input())
for i in range(n):
	s = input().split()
	print(to_mcxi(from_mcxi(s[0]) + from_mcxi(s[1])))
