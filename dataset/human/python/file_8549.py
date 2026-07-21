import numpy as np
K, N = map(int, input().split(' '))

dis = list(map(int, input().split(' ')))
dis = [__ - dis[0] for __ in dis]
dis.insert(0, 0)
dis = np.array(dis[1:]) - np.array(dis[:-1])
dis = list(dis)
dis.append(K - sum(dis))
#print(dis)
dis = sorted(dis)

print(sum(dis[1:-1]))
