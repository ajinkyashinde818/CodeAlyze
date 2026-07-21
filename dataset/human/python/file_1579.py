n, m = list(map(int, input().split()))
aa, bb = [], []
for _ in range(n):
    aa.append(input())
for _ in range(m):
    bb.append(input())

ans = 'No'
from itertools import product
for i, j in product(range(n - m + 1), repeat=2):
    ok = True
    for x, y in product(range(m), repeat=2):
        if aa[x+i][y+j] != bb[x][y]:
            ok = False
            break
    if ok:
        ans = 'Yes'
        break

print(ans)
