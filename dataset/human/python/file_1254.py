def resolve():
	n = int(input())
	a = list(map(int, input().split()))
	s = [0]*(n+1)
	for i in range(n):
		s[i+1] = s[i] + a[i]
	ans = float('inf')
	for i in range(1, n):
		ans = min(ans, abs(s[-1] - s[i]*2))
	print(ans)
resolve()
