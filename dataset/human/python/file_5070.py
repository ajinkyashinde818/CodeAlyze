import sys

N, M = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(M)]
B = []

for i in range(M):
	if 1 in A[i]:
		B.append(A[i][1])
	elif N in A[i]:
		B.append(A[i][0])

C = set(B)

if len(C) == len(B):
	print("IMPOSSIBLE")
else:
	print("POSSIBLE")
