def resolve():
	d, g = map(int, input().split())
	ps = []
	cs = []
	ans = 100**6
	for _ in range(d):
		p, c = map(int, input().split())
		ps.append(p)
		cs.append(c)
	for i in range(d-1, -1, -1):
		total = 0
		solved = 0
		for _ in range(ps[i]):
			if total >= g and ans > solved:
				ans = solved
			total += 100 * (i + 1)
			solved += 1
		total += cs[i]
		if total >= g and ans > solved:
			ans = solved
			break
		for j in range(1 << d):
			done = False
			t_solved = solved
			t_total = total
			for k in range(d-1, -1, -1):
				if (j >> k) & 1:
					if i == k:
						continue
					if done:
						break
					for _ in range(ps[k]):
						if done:
							break
						if t_total >= g and ans > t_solved:
							ans = t_solved
							done = True
							continue
						t_total += 100 * (k+1)
						t_solved += 1
					t_total += cs[k]
					if t_total >= g and ans > t_solved:
						ans = t_solved
	print(ans)
resolve()
