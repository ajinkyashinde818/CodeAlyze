import numpy as np
N = int(input())
A = np.array(list(map(int, input().split())))
my_sum = np.sum(np.abs(A))
if np.count_nonzero(A < 0) % 2 == 0:
    print(my_sum)
else:
    print(my_sum - 2 * np.min(np.abs(A)))
