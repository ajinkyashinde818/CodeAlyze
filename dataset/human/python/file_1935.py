import itertools
import sys

n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

for i, j in itertools.product(range(n - m + 1), range(n - m + 1)):
	if a[i][j] == b[0][0]:
		for p, q in itertools.product(range(m), range(m)):
			if a[i + p][j + q] != b[p][q]:
				if i == n - m and j == n - m:
					print('No')
				break
			elif p == m - 1 and q == m - 1:
				print('Yes')
				sys.exit()
				
	elif i == n - m and j == n - m:
		print('No')
