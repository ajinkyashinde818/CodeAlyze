from math import sqrt
from itertools import combinations

n = int(input())
if int(sqrt(2 * n)) * (int(sqrt(2 * n)) + 1) != 2 * n:
	print("No")
else:
	print("Yes")
	k = int(sqrt(2 * n)) + 1
	print(k)
	ans = [[] for _ in range(k)]
	num = 1
	for p in combinations(range(k), r=2):
		#print(p[0], p[1])
		ans[p[0]].append(num)
		ans[p[1]].append(num)
		num += 1
	for i in range(k):
		ans[i] = [k-1] + ans[i]
		print(*ans[i])
