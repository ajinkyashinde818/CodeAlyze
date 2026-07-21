def resolve():
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	rec = [True]*(n+2)
	now = 0
	stp = [1]

	while rec[now]:
		rec[now] = False
		now = a[now] - 1
		stp.append(now+1)
	before_loop = stp.index(now+1)
	loop = stp[before_loop:-1]
	if k <= (before_loop):
		print(stp[k])
	else:
		r = (k - before_loop) % len(loop)
		print(loop[r])
resolve()
