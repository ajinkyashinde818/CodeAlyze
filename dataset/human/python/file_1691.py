n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

from itertools import product
for i,j in product(range(n-m+1), repeat=2):
    t = []
    for k in range(m):
        t.append(a[i+k][j:j+m])

    if t == b:
        print("Yes")
        break

else:
    print("No")
