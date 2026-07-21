def main():
	D, G = map(int, input().split())
	p = [0]*(D+1)
	c = [0]*(D+1)
	ans = 10**9
	for i in range(D):
		p[i], c[i] = map(int, input().split())

	for mask in range(1 << D):
		s, num, rest_max = 0, 0, -1
		for i in range(D):
			if ((mask >> i) & 1) == 1:
				s += 100 * (i+1) * p[i] + c[i]
				num += p[i]
			else:
				rest_max = i
		if s < G:
			s1 = 100 * (rest_max+1)
			need = (G - s + s1 - 1) // s1
			if need >= p[rest_max]:
				continue
			num += need
		ans = min(ans, num)

	print(ans)


if __name__ == '__main__':
    main()
