import pprint
from itertools import product

N, M = [int(n) for n in input().split()]

A = []
for _ in range(N):
    A.append(list(input()))

B = []
for _ in range(M):
    B.append(list(input()))

found = False
for dx, dy in product(range(N - M + 1), repeat=2):
    found = True
    for x, y in product(range(M), repeat=2):
        if A[dx + x][dy + y] != B[x][y]:
            found = False
            break
    if found:
        break
    
print('Yes' if found else 'No')
