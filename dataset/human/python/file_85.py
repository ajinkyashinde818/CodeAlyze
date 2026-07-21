R, G, B, N = map(int, input().split())

import numpy as np

r = np.arange(0, N+1, R, dtype=np.int64)
g = np.arange(0, N+1, G, dtype=np.int64)
r, g = np.meshgrid(r, g)
b = N - r - g

print(np.sum(((b%B)==0) & (b>=0)))
