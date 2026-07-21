import numpy as np

n, m = map(int, input().split())
from_1 = np.zeros(n+1, dtype=np.int)
to_n = np.zeros(n+1, dtype=np.int)
for i in range(m):
    a, b = map(int, input().split())
    if a == 1:
        from_1[b] = 1
    elif b == n:
        to_n[a] = 1

print('IMPOSSIBLE') if np.sum(from_1*to_n) == 0 else print('POSSIBLE')
