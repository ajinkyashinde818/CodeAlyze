import numpy as np

N = int(input())
A = [int(i) for i in input().split()] 
Acnt = 0
for i in range(N):
	if A[i] < 0:
		Acnt += 1

if Acnt % 2 == 1:
	print(np.sum(np.abs(A)) - np.min(np.abs(A))*2)
elif Acnt % 2 == 0:
	print(np.sum(np.abs(A)))
