def getlist():
	return list(map(int, input().split()))

N = int(input())
A = getlist()
B = getlist()
C = getlist()
ans = 0

for i in range(N):
	ans += B[A[i] - 1]

for i in range(N - 1):
	if A[i + 1] - A[i] == 1:
		ans += C[A[i] - 1]

print(ans)
