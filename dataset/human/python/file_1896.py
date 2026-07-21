from itertools import product
n, m = list(map(int, input().split()))
A = [list(input()) for _ in range(n)]
B = [list(input()) for _ in range(m)]
for i, j in product(range(n - m + 1), range(n - m + 1)):
    if all([A[i + k][j:j + m] == B[k] for k in range(m)]):
        print('Yes')
        exit()
print('No')
