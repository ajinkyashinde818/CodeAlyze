import collections

N = int(input())

A = list()
if N == 1:
	A.append(1)
else:
	while N%2 == 0:
		A.append(2)
		N = N//2
	f = 3
	while f*f <= N:
		if N % f == 0:
			A.append(f)
			N = N//f
		else:
			f += 2
	if N != 1:
		A.append(N)

A = collections.Counter(A)
del A[1]
count = 0

for a in A.values():
	n = 1
	th = n*(n+1)/2
	while a >= th:
		n += 1
		th = n*(n+1)/2
	count += n-1

print(count)
