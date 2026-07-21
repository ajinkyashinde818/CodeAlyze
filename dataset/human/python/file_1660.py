import sys
import numpy as np

n,m = map(int, input().split())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]
a = np.array(a)
b = np.array(b)

for i in range(0, n-m+1):
    for j in range(0, n-m+1):
        if (a[i:i+m,j:j+m] == b).all():
            print('Yes')
            sys.exit()

print('No')
