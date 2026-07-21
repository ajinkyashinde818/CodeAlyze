import sys

max_dist = -1

p, n = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n):
	if i == n - 1:
		max_dist = max(max_dist, p + a[0] - a[i])
	else:
		max_dist = max(max_dist, a[i + 1] - a[i])

print(p - max_dist)
