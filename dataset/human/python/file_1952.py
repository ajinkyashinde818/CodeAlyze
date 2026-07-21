from sys import exit

def func(i,j):
	f=True
	for x in range(M):
		for y in range(M):
			if A[i+x][j+y]!=B[x][y]:
				f=False
	return f


N,M=map(int,input().split())
A = []
B = []

for i in range(N):
	A.append(list(map(lambda x:1 if x=='#' else 0, input())))

for i in range(M):
	B.append(list(map(lambda x:1 if x=='#' else 0, input())))


for i in range(N-M+1):
	for j in range(N-M+1):
		if func(i,j):
			print('Yes')
			exit()

print('No')
