import sys
N, M = map(int,input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        new = [A[k][j:j+M] for k in range(i,i+M)]
        if new == B:
            print('Yes')
            sys.exit()
print('No')
