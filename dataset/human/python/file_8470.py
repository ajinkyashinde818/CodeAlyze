import sys

K, N = map(int,input().split())
A = list(map(int,input().split()))
L = [0]*(2*N)
MIN = 1e18

for i in range(0,N):
	L[i] = A[i]
for i in range(N,2*N):
	L[i] = A[i-N]+K
for i in range(N-1,2*N):
	MIN = min(MIN,L[i]-L[i-(N-1)])

print(MIN)
