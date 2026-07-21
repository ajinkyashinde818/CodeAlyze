def judge(a, b, y, x, m):
	for i in range(0, m):
		for j in range(0, m):
			if a[y+i][x+j] != b[i][j]: return False
	return True

N, M = map(int, raw_input().split())
A = []
B = []
for i in range(0, N):
	A.append(raw_input())
for i in range(0, M):
	B.append(raw_input())

ans = 'No'
for i in range(0, N-M+1):
	for j in range(0, N-M+1):
		if judge(A, B, i, j, M):
			ans = 'Yes'
			break

print ans
