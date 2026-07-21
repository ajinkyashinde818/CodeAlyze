import math
import os
import sys

import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import dijkstra

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

SX, SY, TX, TY = list(map(int, sys.stdin.readline().split()))
N = int(sys.stdin.readline())
X, Y, R = list(zip(*[map(int, sys.stdin.readline().split()) for _ in range(N)]))

X = np.concatenate([X, [SX, TX]])
Y = np.concatenate([Y, [SY, TY]])
R = np.concatenate([R, [0, 0]])

S = N
T = N + 1
XI, XJ = np.meshgrid(X, X)
YI, YJ = np.meshgrid(Y, Y)
RI, RJ = np.meshgrid(R, R)
V, U = np.meshgrid(np.arange(N + 2), np.arange(N + 2))
D = np.maximum(0, np.sqrt(np.power(XI - XJ, 2) + np.power(YI - YJ, 2)) - RI - RJ)

ret = dijkstra(csr_matrix((D.ravel(), (U.ravel(), V.ravel()))), directed=False, indices=S)
print(ret[T])
