def resolve():
	n, m = map(int, input().split())
	A = []
	B = []
	ans = False
	for _ in range(n):
		A.append(list(input()))
	for _ in range(m):
		B.append(list(input()))
	for i in range(n):
		for j in range(n):
			if i + m - 1 >= n or j + m - 1 >= n:
				continue
			tmp_ans = True
			for k in range(m):
				for l in range(m):
					if A[i+k][j+l] != B[k][l]:
						tmp_ans = False
						break
			if tmp_ans:
				ans = 'Yes'


	if ans:
		print('Yes')
	else:
		print('No')
resolve()
