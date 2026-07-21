import numpy as np

n, m = map(int, input().split())
A = np.array([list(input()) for _ in range(n)])
B = np.array([list(input()) for _ in range(m)])

for i in range(n-m+1):
    for j in range(n-m+1):
        if (A[i:i+m, j:j+m] == B).all():
            print('Yes')
            exit()
print('No')
