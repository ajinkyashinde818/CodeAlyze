import sys

readline = sys.stdin.readline
N, M = map(int, readline().split())
A = [readline().rstrip() for _ in range(N)]
B = [readline().rstrip() for _ in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        if all(A[i+x][j:j+M] == B[x] for x in range(M)):
            print('Yes')
            sys.exit()
print('No')
