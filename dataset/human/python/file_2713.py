import math
D, G = map(int, input().split())
p = {}
c = {}
for i in range(D):
	p[i], c[i] = map(int, input().split())
ans = 9999
for i in range(1 << D):
	rest_max = -1
	sum = 0
	n = 0
	for j in range(D):
		if (i >> j) & 1 == 1:
			sum = sum + p[j] * (j + 1) * 100 + c[j]
			n = n + p[j]
		else:
			rest_max = j
	if rest_max == -1:
		ans = min(ans, n)
		continue
	if sum + (p[rest_max] - 1) * (rest_max + 1) * 100 < G:
		continue
	n = n + max(math.ceil((G - sum) / 100 / (rest_max + 1)), 0)
	ans = min(ans, n)
	#print(i, ans)
print(ans)
