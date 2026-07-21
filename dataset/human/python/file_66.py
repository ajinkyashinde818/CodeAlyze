import numpy as np
R, G, B, N = map(int, input().split())
r = np.arange(0, int(N/R)+1)
g = np.arange(0, int(N/G)+1)
rg = r[:, np.newaxis]*R+g[np.newaxis, :]*G
mask = (rg<=N) & ((N-rg)%B==0)
print(np.sum(mask))
