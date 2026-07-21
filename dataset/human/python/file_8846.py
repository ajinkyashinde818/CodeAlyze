import numpy as np

import sys

readline = sys.stdin.buffer.readline

K, N = map(int, readline().split())
A = list(map(int, readline().split()))
A.append(K + A[0])

D = np.diff(A)

print(int(K) - np.max(D))
