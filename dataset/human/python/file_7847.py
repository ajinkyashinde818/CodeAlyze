import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    
N,K,S=map(int,input().split())

if S==10**9:
	for i in range(K):
		print(10**9)
	for j in range(N-K):
		print(12445677)

else:
	for j in range(N-K):
		print(S+1)
	for i in range(K):
		print(S)
