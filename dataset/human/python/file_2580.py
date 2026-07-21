import numpy as np
import itertools
import math

D, G = tuple(map(int, input().split()))

p_c_list = np.array([tuple(map(int, [100 * (i + 1)] + input().split())) for i in range(D)])

masks = itertools.product([False, True], repeat=len(p_c_list))

ret = np.inf
for mask in masks:
  maskedarr = p_c_list[np.array(mask), :]
  comp_sum = (maskedarr[:, 0] * maskedarr[:, 1] + maskedarr[:, 2]).sum()
  suc_num = maskedarr[:, 1].sum()
  if comp_sum < G:
    amari = (G - comp_sum) / p_c_list[~np.array(mask), 0][-1]
    if amari < p_c_list[~np.array(mask), 1][-1]:
      if ret > suc_num + amari:
        ret = suc_num + amari
    else:
      continue
  elif suc_num < ret:
    ret = suc_num
  else:
    continue
    
print(int(math.ceil(ret)))
