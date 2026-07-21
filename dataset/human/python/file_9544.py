import sys
import numpy as np
N, K = map(int, input().split())
A = np.array(list(map(int, input().split())))
A = np.insert(A, 0, 0)

flg = [False for _ in range(N + 1)]
town = []
i = 1
cnt = 0
for _ in range(N):
    town.append(i)
    flg[i] = True
    i = A[i]

if len(town) >= K:
    print(town[K])
else:
    s = i
    to_s = town.index(s)
    loop = len(town) - to_s
    print(town[(K - to_s) % loop + to_s])
