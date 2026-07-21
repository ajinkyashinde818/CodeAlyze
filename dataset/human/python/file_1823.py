N, M = map(int, input().split())
A, B = [], []

for i in range(N):
	a = list(map(str, input()))
	A.append(a)
	
for i in range(M):
	b = list(map(str, input()))
	B.append(b)
	
def foo():
	for si in range(N - M + 1):
		for sj in range(N - M + 1):
			flg = 1
			for i in range(M):
				if not A[si + i][sj : sj + M] == B[i]:
					flg = 0
					break
			if flg:
				print("Yes")
				return 0
	print("No")
	return 0
	
foo()
