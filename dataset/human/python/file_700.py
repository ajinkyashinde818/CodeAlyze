import numpy as np
from collections import deque

xs, ys, xt, yt = map(int, raw_input().split())
N = int(raw_input())
X = [xs]
Y = [ys]
R = [0]
for _ in range(N):
    x, y, r = map(int, raw_input().split())
    X.append(x)
    Y.append(y)
    R.append(r)
X.append(xt)
Y.append(yt)
R.append(0)

X_np = np.array(X)
Y_np = np.array(Y)
R_np = np.array(R)

dist = np.zeros((N+2, N+2))
for i in range(N+2):
    dist[i, :] = np.maximum(np.sqrt((X_np - X_np[i])**2 + (Y_np - Y_np[i])**2) - (R_np + R_np[i]), 0)

cost = 4000000000.0 * np.ones(N+2)
cost[0] = 0
# with minnimum cost
q = 0
unfixed_list = range(N+2)
unfixed_list.remove(q)


while len(unfixed_list) > 0:
    new_cost = cost[q] + dist[q, :]
    cost = np.minimum(cost, new_cost)
    q = unfixed_list[cost[unfixed_list].argmin()]
    unfixed_list.remove(q)
    

print cost[N+1]
