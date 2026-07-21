import sys

N , M = [int(n) for n in input().split()]

A=[]
B=[]
for i in range(N):
    A.append(input())
for i in range(M):
    B.append(input())

for i in range(N-M+1):
    for j in range(N-M+1):
        corres = True
        for k in range(M):
            if A[i+k][j:j+M] != B[k]:
                corres = False
                break
        if corres == True:
            print('Yes')
            sys.exit()

print('No')
