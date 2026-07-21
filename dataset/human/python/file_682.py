import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

import numpy as np
from scipy.spatial.distance import cdist
from scipy.sparse.csgraph import dijkstra, csgraph_from_dense

xs, ys, xt, yt = map(int, readline().split())
n = int(readline())
xyr = np.array(read().split(), np.int64)
xyr = np.append(xyr, [xs, ys, 0, xt, yt, 0])
xyr = xyr.reshape((-1, 3))

xy = xyr[:, :2]
dist = cdist(xy, xy)
r = xyr[:, 2]
dist = np.maximum(dist - r - r.reshape((-1, 1)), 0)
dist[np.arange(n+2), np.arange(n+2)] = np.inf
g = csgraph_from_dense(dist, null_value=np.inf)

ans = dijkstra(g, indices=n)[n+1]
print(ans)
