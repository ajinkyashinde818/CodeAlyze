from itertools import product

N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for i, j in product(range(N-M+1), range(N-M+1)):
    A_partial = [a[j:j+M] for a in A[i:i+M]]
    if A_partial == B:
        print('Yes')
        break
else:
    print('No')
