import sys
input = sys.stdin.readline
import numpy as np
from scipy.sparse.csgraph import csgraph_from_dense, dijkstra
from scipy.spatial.distance import cdist

xs,ys,xt,yt = map(int,input().split())
N = int(input())
XYR = np.empty((N+2,3),dtype=np.int64)
XYR[:2,] = [[xs,ys,0], [xt,yt,0]]

XYR[2:] = np.array([input().split() for _ in range(N)], dtype=np.int64)

XY = XYR[:,:2]
dist = cdist(XY, XY)
R = XYR[:,2]
dist -= R[:,None] + R[None,:]
np.maximum(dist, 0, out = dist)
dist[np.arange(N+2), np.arange(N+2)] = np.inf

graph = csgraph_from_dense(dist, null_value = np.inf)

answer = dijkstra(graph, indices = 0)[1]

print(answer)
