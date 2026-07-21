if __name__ == '__main__':
	S = input()
	Q = int(input())

	c = 1

	A = ''
	B = ''

	for i in range(Q):
		I = input()
		if len(I) == 1:
			c = c * (-1)
		else:
			T, F, C = I.split()
			f = int(F)
			if f == 1 and c == 1:
				A = C + A
			elif f == 1 and c == -1:
				B = B + C
			elif f == 2 and c == -1:
				A = C + A
			else:
				B = B + C

	S = A + S + B

	if c == -1:
		S = S[::-1]

	print(S)
