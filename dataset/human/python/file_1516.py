import sys

N, M = map(int, input().split())
A = [list(input()) for i in range(N)]
B = [list(input()) for i in range(M)]

for k in range(N-M+1):
    for i in range(N-M+1):
        a = [A[j+k][i:i+M] for j in range(M)]
        if a == B:
            print('Yes')
            sys.exit()

print('No')
