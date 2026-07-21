if __name__ == '__main__':
	N,K = map(int, input().split())
	des = [int(a) for a in input().split()]
	ind = [0] * N
	ind[0] = 1
	h = 1
	c = 2
	check = 0
	while(check == 0):
		d = des[h-1]
		if ind[d-1] == 0:
			ind[d-1] = c
			c += 1
		else:
			check = 1
		h = d
	L = ind[d-1]
	R = c
	term = R-L
	if K <= L:
		ans = ind.index(K+1) + 1
	else:
		ans = ind.index(L + (K+1-L)%term)+1
	print(ans)
