import math
n = int(raw_input())
ans = 0

for i in range(2, int(math.sqrt(n) + 1)):
	if n % i == 0:
		p = i
		cnt = 0
		while n % i == 0:
			n /= i
			cnt += 1
		start = 1
		while start <= cnt:
			ans += 1
			cnt -= start
			start += 1
if n > 1:
	ans += 1
print ans
