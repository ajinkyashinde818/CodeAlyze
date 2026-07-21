from collections import Counter
N = int(input())

LIM = int(N ** .5) + 10
P = [True] * LIM
P[0] = P[1] = False
for i in range(4, LIM, 2): P[i] = False
i = 3
while i * i < LIM:
	if P[i]:
		j = i * i
		while j < LIM:
			P[j] = False
			j += 2 * i
	i += 2

pr = []
for i in range(2, LIM):
	if P[i]:
		pr.append(i)


if N == 1:
	print(0)
else:
	factors = Counter()
	for p in pr:
		if p > N: break
		while N % p == 0:
			factors[p] += 1
			N //= p

	if N > 1:
		factors[N] += 1

	r = 0
	for k, v in factors.items():

		i = 1
		while v >= i:
			r += 1
			v -= i
			i += 1
	print(r)
