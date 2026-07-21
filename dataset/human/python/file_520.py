import sys
import numpy as np
input = sys.stdin.readline

def main():
	N = int(input())
	A = list(map(int,input().split()))
	A.sort()
	count = 0
	m = 10**10
	if 0 in A:
		A = np.array(A)
		print(sum(abs(A)))
	else:
		for i in range(N):
			if A[i]<0:
				count += 1
			m = min(m,abs(A[i]))
		A = np.array(A)
		if count%2 == 0:
			print(sum(abs(A)))
		else:
			print(sum(abs(A))-2*m)

if __name__ == "__main__":
	main()
