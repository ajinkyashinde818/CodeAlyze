def daydream():
	S = input()
	flag = False
	divide = ['dreamer', 'dream', 'eraser', 'erase']
	while True:
		if len(S) == 0:
			flag = True
			break
		for d in divide:
			if S.endswith(d):
				S = S[:-len(d)]
				break
		else:
			break
	if flag:
		print('YES')
	else:
		print('NO')

daydream()
