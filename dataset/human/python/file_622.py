import numpy as np

N = int(input())
A = [int(x) for x in input().split()]

A = np.array(A)

plus = A[A >= 0]
minus = A[A < 0]

if len(minus) % 2 == 0:
    ans = np.sum(plus) - np.sum(minus)
else:
    ans = np.sum(plus) - np.sum(minus) - np.min(np.abs(A)) * 2

print(ans)
