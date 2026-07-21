import itertools
N, M = [int(_) for _ in input().split()]
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for i, j in itertools.product(range(N-M+1), repeat=2):
    if [_[j:j+M] for _ in A[i:i+M]] == B:
        print('Yes')
        exit()
print('No')
