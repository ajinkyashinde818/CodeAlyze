from sys import stdin,stdout
N,K,S = map(int,stdin.readline().split())
A = [0 for i in range(N)]
waste = N - K
wasteval = 1000000000 if S != 1000000000 else 999999999
for i in range(waste):A[i] = wasteval
for i in range(waste,N):A[i] = S
[print(i,end=' ') for i in A ]
