def resolve():
	n, m = map(int, input().split())
	v = [[] for i in range(n+1)]
	for i in range(m):
		a, b = list(map(int, input().split()))
		v[a].append(b)
	ans = 'IMPOSSIBLE'
	for i in range(len(v[1])):
		if n in v[v[1][i]]:
			ans = 'POSSIBLE'
			break
	print(ans)
resolve()
