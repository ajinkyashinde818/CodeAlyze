def main():
	N = int(input())
	A= list(map(int, input().split()))
	pos = []
	neg = []
	ans = 0
	min_neg = 10**9
	min_pos = 10**9
	for i in range(N):
		if A[i] > 0:
			pos.append(A[i])
			min_pos = min(min_pos, A[i])
		else:
			neg.append(-A[i])
			min_neg = min(min_neg, -A[i])
	ans = sum(neg)+sum(pos)
	if len(neg)%2 == 1:
		ans -= 2*min(min_pos, min_neg) 
	print(ans)


if __name__ == '__main__':
    main()
