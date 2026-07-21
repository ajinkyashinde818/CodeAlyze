import numpy as np

K,N = map(int, input().split())
An_list = np.array(input().split(), dtype=int)

An_delta_list = np.diff(An_list)
An_delta_list = np.append(An_delta_list, (K - An_list[-1])+An_list[0])
An_delta_max = np.max(An_delta_list)
result = np.sum(An_delta_list) - An_delta_max
print(result)
