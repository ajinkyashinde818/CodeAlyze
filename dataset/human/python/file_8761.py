import numpy as np

K, N = map(int, input().split())
an = [int(x) for x in input().split()]
arr = np.array(an)

dist = arr[1:] - arr[:-1]
dist = list(dist)
dist.append(K - an[N-1] + an[0])

print(K - max(dist))
