import numpy as np

K, N = map(int, input().split(" "))
loc = list(map(int, input().split(" ")))
loc = np.array(loc)

dist = np.diff(loc)
dist = np.append(dist, K - loc[N - 1] + loc[0])

most_far = np.max(dist)
print(K - most_far)
