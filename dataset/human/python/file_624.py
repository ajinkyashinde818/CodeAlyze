n = int(input())
A = list(map(int, input().split(' ')))

import numpy as np

neg_cnt = len(list(filter(lambda x: x<0, A)))
abs_lis = np.abs(A)
sum_abs = sum(abs_lis)
if neg_cnt % 2 ==0:
    print(sum_abs)
else:
    print(sum_abs-2*min(abs_lis))
