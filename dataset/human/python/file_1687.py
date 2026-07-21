import itertools
N,M = map(int, input().strip().split(' '))
A = [input().strip() for _ in range(N)]
B = [input().strip() for _ in range(M)]
for i,j in itertools.product(range(N-M+1), repeat=2):
  if sum(A[y+i][j:j+M] == B[y] for y in range(M)) == M:
    print('Yes')
    exit()
print('No')
