import numpy as np
n,m = list(map(int, input().split()))
tmp_a = [list(input()) for _ in range(n)]
tmp_b = [list(input()) for _ in range(m)]

a = np.array(tmp_a)
b = np.array(tmp_b)

for a_i in range(n - m + 1):
	for a_j in range(n - m + 1):
		if((a[a_i:a_i + m, a_j:a_j + m] == b).all()):
			print("Yes")
			exit()
print("No")
