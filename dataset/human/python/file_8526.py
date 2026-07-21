if __name__ == '__main__':
	K, N = map(int, input().split())
	A = [int(a) for a in input().split()]

	m = 0

	for i in range(N-1):
		sa = A[i+1] - A[i]
		if sa > m:
			m = sa

	if K - A[N-1] + A[0] > m:
		m = K - A[N-1] + A[0]

	print(K-m)
