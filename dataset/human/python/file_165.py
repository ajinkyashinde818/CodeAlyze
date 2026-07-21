def main():
	R, G, B, N = map(int, input().split())
	r_max, g_max = N//R, N//G
	def search(ball, goal):
		if goal % ball == 0:
			return 1
		return 0
	ans = search(R, N)
	ans += search(G, N)
	ans += search(B, N)
	for r in range(1, r_max+1):
		if r*R >= N:
			break
		ans += search(G, N-r*R)
		ans += search(B, N-r*R)
		for g in range(1, g_max+1):
			if r*R+g*G >= N:
				break
			ans += search(B, N-r*R-g*G)

	for g in range(1, g_max+1):
		if g*G >= N:
			break
		ans += search(B, N-g*G)
	print(ans)


if __name__ == '__main__':
	main()
