import numpy as np


A = list(map(int, input().split()))
K = A[0]
S = A[1]
counter = 0
for i in range(K+1):
	for j in range(K+1):
		sa = S - (i + j)
		if 0 <= sa and sa <= K:
			counter = counter + 1
			
			
print(counter)
print("\n")
