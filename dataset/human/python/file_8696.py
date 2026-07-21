import numpy as np

k, n = map(int, input().split())
a_list = [int(i) for i in input().split()]
a_list += [a_list[0]+k]

a_list = np.array(a_list)

dif = a_list[1:] - a_list[:-1]
dif_max = np.max(dif)

print(k-dif_max)
