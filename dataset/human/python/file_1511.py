from itertools import product
N, M = list(map(int, input().split()))
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]
flag = False

for _i, _j in product(range(N - M + 1), range(N - M + 1)):
    if A[_i][_j] == B[0][0] and [_A[_j:_j+M] for _A in A[_i:_i+M]] == B:
        flag = True
        break
if flag:
    print('Yes')
else:
    print('No')
