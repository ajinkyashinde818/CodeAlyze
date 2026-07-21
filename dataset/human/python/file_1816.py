def match_m(x, y, N, M, A, B):
	for i in range(M):
		if x+i >= N: return False
		for j in range(M): 
			if y+j >= N: return False
			if A[x+i][y+j] != B[i][j]: return False
	return True

N, M = map(int, raw_input().split())
A, B = [], []
for i in range(N): A.append(raw_input())
for i in range(M): B.append(raw_input())
result = "No"
for x in range(N):
	for y in range(N):
		if(match_m(x,y,N,M,A,B)): 
			result = "Yes"
			break
print result
