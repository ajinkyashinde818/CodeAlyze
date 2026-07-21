import numpy as np
N = int(input())
alist = np.array(list(map(int, input().split())))
snk = np.cumsum(alist)[:-1]
ari = np.cumsum(alist[::-1])[::-1][1:]
print(np.min(np.abs(snk - ari)))
