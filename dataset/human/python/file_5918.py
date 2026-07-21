if __name__ == '__main__':

	input()
	A = list(map(int,input().split()))
	B = list(map(int,input().split()))
	C = list(map(int,input().split()))

	gokei = 0
	for i in range(1,len(A)):
		if A[i] - A[i-1] == 1:
			gokei += C[A[i-1]-1]

	gokei += sum(B)
	print(gokei)
