import numpy as np
N = int(input())
A = np.array([int(i) for i in input().split()])

minus = len(A[np.where(A < 0)])
abs_list = [abs(0-i) for i in A]
res = sum(abs_list)
if minus % 2 != 0:
    m = min(abs_list)
    res -= m * 2
print(res)
