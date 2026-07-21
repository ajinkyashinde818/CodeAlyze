def getlist():
	return list(map(int, input().split()))

N = int(input())
A = getlist()
j = 0
for i in range(N):
	if A[i] <= 0:
		j += 1
	A[i] = abs(A[i])

A = sorted(A)
if j % 2 == 0:
	print(sum(A))
else:
	print(sum(A) - 2 * A[0])
