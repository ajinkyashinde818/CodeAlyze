import numpy as np

k, n = map(int, input().split())
A = np.array(list(map(int, input().split())))
B = A[1:]
dist = B - A[:-1]
dist = np.append(dist, k-A[-1]+A[0])
print(np.sum(dist) - np.max(dist))
