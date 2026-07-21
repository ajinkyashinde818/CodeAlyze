import numpy as np
import heapq

k, n = map(int, input().split())

As = np.asarray(input().split(), dtype=np.int32)

H = []

for i in range(len(As)):
    if i == 0:
        heapq.heappush(H, As[-1]-k-As[0])
    else:
        heapq.heappush(H, As[i-1] - As[i])

print(k + H[0])
