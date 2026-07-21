from itertools import product

n, m = [int(x) for x in input().split()]

a = [input() for x in range(n)]
b = [input() for x in range(m)]
ret = 'No'

for i, j in product(range(n - m + 1), range(n - m + 1)):
    if all([a[i + k][j:m + j] == x for k, x in enumerate(b)]):
        ret = 'Yes'
        break
print(ret)
