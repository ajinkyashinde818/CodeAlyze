import itertools

def main():
	d, g = list(map(int, input().split()))
	problems = [list(map(int, input().split())) for _ in range(d)]

	ptns = list(itertools.product([0, 1], repeat = d))

	ans = 10 ** 10

	for pt in ptns:
		rest = g - sum([((i + 1) * 100 * problems[i][0] + problems[i][1]) * pt[i] for i in range(d)])
		tmp = sum([problems[i][0] * pt[i] for i in range(d)])
		
		if rest > 0:
			if 0 in pt:
				rest_max_idx = d - pt[::-1].index(0) - 1
				#print(pt, tmp, rest_max_idx, rest)
				for i in range(problems[rest_max_idx][0]):
					rest -= (rest_max_idx + 1) * 100
					tmp += 1
					if rest <= 0:
						break

		if rest <= 0:
			ans = min(ans, tmp)

	print(ans)


if __name__ == '__main__':
	main()
