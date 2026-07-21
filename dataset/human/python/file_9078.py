def resolve():
	s = input()
	K = ['dream', 'dreamer', 'erase', 'eraser']
	for i in range(len(K)):
		K[i] = K[i][::-1]
	r = ''
	for i in s[::-1]:
		r += i
		if r in K:
			r = ''
	if len(r):
		print("NO")
	else:
		print("YES")
resolve()
