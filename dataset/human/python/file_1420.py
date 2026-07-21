import numpy as np
N = int(input())
A = list(map(int, input().split()))

A_r = A[::-1]

cumsum_A = np.cumsum(A)
cumsum_A_r = np.cumsum(A_r)

x = [abs(a - a_r) for (a, a_r) in zip(cumsum_A[:-1], cumsum_A_r[-2::-1])]
print(min(x))
