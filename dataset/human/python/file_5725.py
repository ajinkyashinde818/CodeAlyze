def ch(s):
	a = True
	for k, x in enumerate(s):
		if x != s[-k-1]:
			a = False
			break
	return a

s = input()
ns = s.replace("x", "")
if ch(ns):
	a = [0]*(len(ns)+1)
	k = 0
	b = True
	for i in s:
		if b:
			if i == 'x':
				a[k] += 1
			else:
				b = False
				k += 1
		else:
			if i == 'x':
				b = True
				a[k] += 1
			else:
				k += 1
	k = 0
	for i in range(len(a)//2):
		if a[i] != a[-i-1]:
			k += abs(a[i] - a[-i-1])
	print(k)
else:
	print(-1)
