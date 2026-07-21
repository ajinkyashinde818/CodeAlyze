import numpy as np
R, G, B, N = map(int, input().split())
M = N - np.add.outer(np.arange(0, N + 1, R, dtype=np.int32), np.arange(0, N + 1, G, dtype=np.int32))
print(((M >= 0) & (M % B == 0)).sum())
